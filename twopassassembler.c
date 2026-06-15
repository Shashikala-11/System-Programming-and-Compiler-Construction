#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct symtab {
    char label[20];
    int addr;
} sym[50];

int symcount = 0;

// Search symbol in SYMTAB
int search(char *label) {
	int i;
    for(i = 0; i < symcount; i++) {
        if(strcmp(sym[i].label, label) == 0)
            return sym[i].addr;
    }
    return -1;
}

// Get opcode value
int getOpcode(char *op) {
    if(strcmp(op, "LDA") == 0) return 1;
    if(strcmp(op, "STA") == 0) return 2;
    if(strcmp(op, "ADD") == 0) return 3;
    if(strcmp(op, "SUB") == 0) return 4;
    if(strcmp(op, "JMP") == 0) return 5;
    return -1;
}

int main() {
    FILE *fp, *inter, *symf, *out;
    char label[20], opcode[20], operand[20];
    int locctr = 100, addr,i;

    // PASS 1
    fp = fopen("input.txt", "r");
    inter = fopen("intermediate.txt", "w");
    symf = fopen("symtab.txt", "w");

    while(fscanf(fp, "%s %s %s", label, opcode, operand) != EOF) {

        // If label is not "-", store in SYMTAB
        if(strcmp(label, "-") != 0) {
            if(search(label) == -1) {
                strcpy(sym[symcount].label, label);
                sym[symcount].addr = locctr;
                symcount++;
            }
        }

        // Write to intermediate file
        fprintf(inter, "%d %s %s %s\n", locctr, label, opcode, operand);

        locctr++; // increment address
    }

    // Write SYMTAB
    for(i = 0; i < symcount; i++) {
        fprintf(symf, "%s %d\n", sym[i].label, sym[i].addr);
    }

    fclose(fp);
    fclose(inter);
    fclose(symf);

    printf("Pass 1 completed.\n");

    // PASS 2
    inter = fopen("intermediate.txt", "r");
    out = fopen("output.txt", "w");

    int opcode_val;

    while(fscanf(inter, "%d %s %s %s", &addr, label, opcode, operand) != EOF) {

        opcode_val = getOpcode(opcode);

        int op_addr = search(operand); // get address of operand

        if(opcode_val != -1 && op_addr != -1) {
            fprintf(out, "%d %d %d\n", addr, opcode_val, op_addr);
        }
    }

    fclose(inter);
    fclose(out);

    printf("Pass 2 completed.\n");

    return 0;
}
