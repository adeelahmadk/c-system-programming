# Information Hard-Coded in Strings

## Vulnerabilities

- information hard-coded in strings (`.rodata`)

## Inspection of Compiled Binaries

- Inspect all sections by using `objdump -s bufftest`.
- Display strings `readelf -x '.rodata' bufftest`
- Look at the symbol table by `readelf --symbols bufftest` or `objdump --syms bufftest`

## Binary Inspection

We can look at the stored information (e.g. password) using utility like `strings`:


```sh
strings plainpass
# or just from data sections
strings	-d plainpass
```

The `objdump` utility is another example:

```sh
objdump -s plainpass
```
Any hex editor can be used to change the values of these strings inside the compiled binaries.
