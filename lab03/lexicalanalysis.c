#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int i=0;
	char str[100];
	
	printf("Enter Code:\n");
	gets(str);
	
	while(str[i]!='\0')
	{
		if(isalpha(str[i]))
		printf("%c -->Identifier\n",str[i]);
		
		else if(isdigit(str[i]))
		printf("%c -->Number\n",str[i]);
		
		else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')	
		printf("%c -->Operator\n",str[i]);
		
	i++;
	
	}
		return 0;
}
