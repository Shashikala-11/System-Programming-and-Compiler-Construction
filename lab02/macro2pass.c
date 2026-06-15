#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mnt{
	char name[20];
	int mdt_index;
	
}mnt[10];

struct mdt{
	char line[100];
}mdt[50];

int mntc=0;
int mdtc=0;

// search macro in mnt
int searchMNT(char *name)
{
	int i;
	for(i=0;i<mntc;i++)
	{
		if(strcmp(mnt[i].name,name)==0)
		{
			return mnt[i].mdt_index;
		}
	}
	return -1;
}

int main()
{
	FILE *inter,*fp,*out;
	char line[100],word[20];
	int i,index;
	//pass1
	fp = fopen("input.txt", "r");
    printf("File opened successfully\n");
	inter=fopen("intermediate_code.txt","w");
	
	while(fgets(line,sizeof(line),fp))
	{
		 if(sscanf(line,"%s",word) != 1)
        continue;  // skip empty lines
printf("READ: %s", line); 
		sscanf(line,"%s",word);
		
		//if macro starts
		if(strcmp(word,"MACRO")==0)
		{
			
			fgets(line,sizeof(line),fp);
			sscanf(line,"%s",word);
			
			mnt[mntc].mdt_index=mdtc;
			strcpy(mnt[mntc++].name,word);
			
			//store body
			while(1)
			{
				fgets(line,sizeof(line),fp);
				
				if(strncmp(line,"MEND",4)==0)
				{
					strcpy(mdt[mdtc++].line,line);
					break;
				}
				strcpy(mdt[mdtc++].line,line);
			}
		}
		else
		{
			fputs(line,inter);
		}
	}
	
	fclose(fp);
	fclose(inter);
	printf("pass 1 completed");
	
	
	//pass 2
	
	inter=fopen("intermediate_code.txt","r");
	out=fopen("out.txt","w");
	
	while (fgets(line,sizeof(line),inter))
	{
		sscanf(line,"%s",word);
		
		index=searchMNT(word);
		
		if(index!=-1)
		{
			for(i=0;i<mdtc;i++)
			{
				fputs(mdt[i].line,out);
			}
		}
		else{
			fputs(line,out);
		}
	}
	
	fclose(inter);
	fclose(out);
	
	return 0;
	
}

































































