# Lab02 — Macro Processor / Macro Two-Pass

This folder contains a macro-processing two-pass assembler example.

Quick run:

```bash
gcc macro2pass.c -o macro2pass
./macro2pass < input.txt > out.txt
```

Files:
- `macro2pass.c` — macro processor implementation
- `input.txt` — source with macros
- `intermediate_code.txt` — produced during processing
