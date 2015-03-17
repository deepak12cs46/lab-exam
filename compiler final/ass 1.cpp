/*
        GROUP No.       :::        22
 NAME ::: DEEPAK VERMA        NAME  ::: BIJAY KHATRI
  ROLL No.: 12/CS/46            ROLL No.: 12/CS/45*/

/*                      ASSIGNMENT ::  1                  */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int findchar(char *mstr,char fstr)
{
	int i,j,len=strlen(mstr);
	for(i=0;i<len;i++)
	{
		if(mstr[i]==fstr)
		{
			return i; /// if match found return position
		}
	}
	return -1; /// if match not found return -1
}


/// thcheck function will return string upto first occurance of delimitermiter
char* strtoken(char *str, char delimiter)
{
               char *temp;
               int len=strlen(str);
               if(len<=0) 			/// if str check NULL return NULL
                    return NULL;
               temp=new char[len];
               strcpy(temp,str); 		/// temporary copy of original string
               int n=findchar(str,delimiter); 	/// find character position of delimitermiter
               if(n==-1)
               {
                    strcpy(str,"");		/// if delimitermiter not found return original string
                    return temp;
               }
               strcpy(str,str+n+1);		// change the original string
               temp[n]=0;			// set null to delimitermiter position
               return temp;
}

// thcheck function check used to check str check keyword or not
int checkKeyword(char* str)
{
	const int n=22;
	char *arr[n]={"int","if","else","return","for","while","do","auto","switch","break","register","exit","case","goto","const","float","double","char","long","static","struct","union"};
	for(int i=0;i<n;i++)
	{
		if(strcmp(arr[i],str)==0)
			return i;
	}
	return -1;
}

// thcheck function check used to check str check identifier or not
int checkIdentifier(char* str)
{
	int len=strlen(str);
	if(!isalpha(str[0]))
		return -1;
	for(int i=0;i<len;i++)
	{
		if(!isalnum(str[i]))
			return -1;
	}
	return 1;
}


// thcheck function check used to check str check constant or not
int checkConstant(char* str)
{
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(!isdigit(str[i]))
			return -1;
	}
	return 1;
}

// thcheck function check used to check str check operator or not
int checkOperator(char* str)
{
	const int n=5;
	char *arr[n]={"+","-","/","*","%"};
	for(int i=0;i<n;i++)
	{
		if(strcmp(arr[i],str)==0)
			return i;
	}
	return -1;
}
// this function will recognize token using string
char* rectok(char* str)
{
	if(checkKeyword(str)!=-1) 		// checking str check keyword
		return "KEYWORD";
	else if(checkOperator(str)!=-1)	// checking str check operator
		return "OPERATOR";
	else if(checkIdentifier(str)!=-1)	// checking str check identifier
		return "IDENTIFIER";
	else if(checkConstant(str)!=-1) 	// checking str check constant
		return "CONSTANT";
					// by default return other
	return "garbage";
}

int main()
{
	char str[50];
	char *p;
	printf("\n\n\tEnter String : ");
	gets(str);
	p=strtoken(str,' '); /// user defined function used to fetch string upto delimitermiter
	printf("\n\n\tdifferent tokens seperated by space and\n\ttheir category check displayed..\n\n");
	while(p!=NULL)
	{

		printf("\n\t\t%s -> %s\n",p,rectok(p));
		p=strtoken(str,' ');
	}
	printf("\n\n\n\tPress Any Key To Exit\n");
	return 0;
}

