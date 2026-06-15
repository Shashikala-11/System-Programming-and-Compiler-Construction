#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct symtab{
	char label[20];
	int addr;
	
}sym[50];

int symcount=0;


// Return search address of symbols from symtab
int search(char *label)
{
	int i;
	for (i=0;i<symcount;i++)
	{
		if (strcmp(sym[i].label,label)==0)
		{
			return sym[i].addr;
			
		}
	}
	return -1;
}


int getopcode(char *op)
{
	if(strcmp(op,"LDA")==0)
	return 1;
	if(strcmp(op,"STA")==0)
	return 2;
	if(strcmp(op,"ADD")==0)
	return 3;
	if (strcmp(op,"SUB")==0)
	return 4;
	if(strcmp(op,"JMP")==0)
	return 5;
	return -1;
	
}

	
int main()
{
	FILE *fp,*symf,*inter,*out;
	char label[20],opcode[20],operand[20];
	int locctr=100,addr,i;
	
	int opcode_val;
	//pass 1
	
	fp=fopen("input.txt","r");
	symf=fopen("symtab.txt","w");
	inter=fopen("intermediate_code.txt","w");
	
	while(fscanf(fp,"%s %s %s",label,opcode,operand)!=EOF)
	{
		if(strcmp(label,"-")!=0)
		{
			if(search(label)==-1)
		{
			strcpy(sym[symcount].label,label);
			sym[symcount].addr=locctr;
			symcount++;
		}
		
		if(search(operand)==-1 && strcmp(operand,"-")!=0)
		{
			strcpy(sym[symcount].label,operand);
			sym[symcount].addr=locctr+1;
			symcount++;
		}
	}
// writing to intermediate code, symtab

fprintf(inter,"%d %s %s %s \n",locctr,label,opcode,operand);
locctr++;

}

// writing to symtab
for(i=0;i<symcount;i++)
{
	fprintf(symf,"%s %d\n",sym[i].label,sym[i].addr);
}


fclose(fp);
fclose(inter);
fclose(symf);

printf("Pass 1 Completed");

// pass 2

inter=fopen("intermediate_code.txt","r");
out=fopen("out.txt","w");

while(fscanf(inter,"%d %s %s %s",&addr,label,opcode,operand)!=EOF)
{
	opcode_val=getopcode(opcode);
	
	int op_addr=search(operand);
	
	if(opcode_val!=-1 && op_addr!=-1)
	{
		fprintf(out,"%d %d %d\n",addr,opcode_val,op_addr);
	}
}

fclose(inter);
fclose(out);

printf("\nPass 2 completed");





	
	return 0;
}
