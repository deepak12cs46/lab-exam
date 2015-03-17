#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int top;
char stackk[100];
int precedence[256][256];
char pop(void );
void push(char );
void push(char current)
{
	stackk[++top]=current;
}
char pop()
{
	char temp;
	temp=stackk[top];
	stackk[top--]='\0';
	return temp;
}
int main()
{
	int n,i,ind,flag,j,f1,f2;
	char ch1,ch2,ch3,str[100][100],expr[100],input[100];
	precedence['+']['+']=1;
	precedence['+']['-']=1;
	precedence['+']['*']=0;
	precedence['+']['/']=0;
	precedence['+']['$']=1;

	precedence['-']['+']=1;
	precedence['-']['-']=1;
	precedence['-']['*']=0;
	precedence['-']['/']=0;
	precedence['-']['$']=1;
	
	precedence['*']['+']=1;
	precedence['*']['-']=1;
	precedence['*']['*']=1;
	precedence['*']['/']=1;
	precedence['*']['$']=1;
	
	precedence['/']['+']=1;
	precedence['/']['-']=1;
	precedence['/']['*']=1;
	precedence['/']['/']=1;
	precedence['/']['$']=1;
	printf("ENTER NUMBER OF PRODUCTIONS\n");
	scanf("%d",&n);
	for (i = 0; i < n; ++i)
		scanf("%s",str[i]);
	scanf("%s",expr);
	strcpy(input,expr);
	ind=0;
	top=-1;
	strcat(input,"$");
	push('$');
	f1=flag=1;	
	while(input[ind]!='$' || f1)
	{	
		if (input[ind]!='$' && flag)
			push(input[ind++]);
			printf("stackk things are :::  %s\t\t",stackk);
			printf("input buffer is  :::  %s\t\n",input+ind);
		if(stackk[top]>='a' && stackk[top]<='z')
		{
			for(i=0;i<n;i++)
			{
				if (str[i][2]==stackk[top])
				{
					printf("REDUCED BY  %s\n",str[i]);
					stackk[top]=str[i][0];
					break;
				}
			}
			if ((stackk[top-1]=='+' || stackk[top-1]=='-' || stackk[top-1]=='*' || stackk[top-1]=='/') && (precedence[stackk[top-1]][input[ind]]))
			flag=0;
		}
         else if(stackk[top]=='+' || stackk[top]=='-' || stackk[top]=='*' || stackk[top]=='/')
          	{   flag=1;
          		if (input[ind]=='$' || input[ind]=='+' || input[ind]=='-' || input[ind]=='*' || input[ind]=='/')	
          		{
          			printf("UNACCEPTED   \n");
					f1=0;
					break;
          		}
          	}
		else if (stackk[top]>='A' && stackk[top]<='Z' && stackk[top-1]!='$' && (precedence[stackk[top-1]][input[ind]]))
		{
			for(i=0;i<n;i++)
			{	f2=0;
				if (str[i][3]==stackk[top-1])
				{	ch1=pop();	ch2=pop();	ch3=pop();
					push(str[i][0]);
					printf("REDUCED BY  %s\n",str[i]);
					flag=1;
					f2=1;
					break;
				}
			}
			if (f2==0)
			{		printf("UNACCEPTED   \n");
					f1=0;
					break;
			}
		}
		else if (stackk[top]>='A' && stackk[top]<='Z' && stackk[top-1]=='$' && input[ind]=='$')
		{	printf("ACCEPTED   \n");
			f1=0;
			break;
		}
		else if (!(stackk[top-1]=='+' || stackk[top-1]=='-' || stackk[top-1]=='*' || stackk[top-1]=='/') && input[ind]=='$')
		{	printf("UNACCEPTED   \n");
			f1=0;
			break;
		}
		else continue;
	}
	return 0;
}
