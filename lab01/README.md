# Lab01 — Two-Pass Assembler

This folder contains a two-pass assembler example used for educational purposes.

Quick run:

```bash
gcc twopass.c -o twopass
./twopass < input.txt > out.txt
```

Files:
- `twopass.c` — assembler source
- `input.txt` — sample input (assembly)
- `intermediate_code.txt` — produced by Pass 1
- `symtab.txt` / `symf.txt` — symbol table outputs

Notes: Adjust filenames as needed for different test inputs.
