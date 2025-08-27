package main

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"strconv"
	"syscall"
)

var cgroupfs = "/sys/fs/cgroup"

// docker 			run image <cmd> <params>
// go run main.go 	run		  <cmd> <params>
func main() {
	switch os.Args[1] {
	case "run":
		run()
	case "child":
		child()
	default:
		panic("bad command")
	}
}

/**
 * Runs a command as a containerized child process
 */
func run() {
	fmt.Printf("running %v as %d\n", os.Args[2:], os.Getpid())

	// prep a child process with exec syscall
	cmd := exec.Command("/proc/self/exe", append([]string{"child"}, os.Args[2:]...)...)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	// containerize the  with namespaces
	//   Clone:
	//   - unix timesharing system: hostname isloation
	//   - PID: Process ID isloation
	//   - Mount: receives a copy of the mount point list from parent
	//   Unshare:
	//   - Mount: don't share bind mount inside container with host
	cmd.SysProcAttr = &syscall.SysProcAttr{
		Cloneflags:   syscall.CLONE_NEWUTS | syscall.CLONE_NEWPID | syscall.CLONE_NEWNS,
		Unshareflags: syscall.CLONE_NEWNS,
	}

	must(cmd.Run())
	cleanup()
}

/**
 * Starts a program inside a chroot evironment
 */
func child() {
	fmt.Printf("running %v as %d\n", os.Args[2:], os.Getpid())

	// setup sub cgroup
	cg()

	// prep exec syscall
	must(syscall.Sethostname([]byte("container")))
	must(syscall.Chroot("/tmp/cgtest/ubuntu-fs"))
	must(syscall.Chdir("/"))
	//            src    target  fstype flags data
	syscall.Mount("proc", "proc", "proc", 0, "")

	cmd := exec.Command(os.Args[2], os.Args[3:]...)
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr

	must(cmd.Run())

	//			    target  flags
	syscall.Unmount("/proc", 0)
}

/**
 * Creates a cgroup with pid restriction and
 * adds current process in it
 */
func cg() {
	// cgroupfs := "/sys/fs/cgroup"
	cgPath := filepath.Join(cgroupfs, "cgtest")
	must(os.MkdirAll(cgPath, 0755))
	must(os.WriteFile(filepath.Join(cgPath, "pids.max"), []byte("10"), 0700))

	/* Uses cgroup v1 now mostly extinct in new Linux distros
	// Removes the new cgroup in place after the container exits [replaced by cgroup.events in v2]
	// must(os.WriteFile(filepath.Join(cgPath, "notify_on_release"), []byte("1"), 0700))
	*/

	// adds itself to the cgroup
	must(os.WriteFile(filepath.Join(cgPath, "cgroup.procs"), []byte(strconv.Itoa(os.Getpid())), 0700))

}

/**
 * Cleans up the sub cgroup
 */
func cleanup() {
	cgPath := filepath.Join(cgroupfs, "cgtest")
	fmt.Printf("removing cgroup: %v ...\n", cgPath)
	err := os.RemoveAll(cgPath)
	if err != nil {
		fmt.Println("Error cleaning up directory:", err)
	} else {
		fmt.Println("Directory and its contents successfully deleted.")
	}
}

/**
 * Panics on error
 */
func must(err error) {
	if err != nil {
		panic(err)
	}
}
