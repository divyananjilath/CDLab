%{
	#include<stdio.h>
	#include<stdlib.h>
	int lineNo=1;
%}
%{
int COMMENT=0;
%}
identifier [a-zA-Z][a-zA-Z0-9]*
%%
"void"|"int"|"break"|"char"|"float"|"return"|"for"|"while"|"long"|"const" 	{ printf("\n%3d.\t%-20s\tKeyword",lineNo,yytext); }
"if" {printf("\n%3d.\t%-20s\tFuntion",lineNo,yytext); }
[0-9]+ 										{ printf("\n%3d.\t%-20s\tNumber",lineNo,yytext); }
("_")*[a-zA-Z]("_"|[a-zA-Z]|[0-9])* 						{ printf("\n%3d.\t%-20s\tIdentifier",lineNo,yytext); }
"+"|"-"|"*"|"/"|"%" 								{ printf("\n%3d.\t%-20s\tArithemetic Operator",lineNo,yytext); }
"=" 										{ printf("\n%3d.\t%-20s\tAssignment Operator",lineNo,yytext); }
"{"|"}"|"("|")"|"."|";"|"," 							{ printf("\n%3d.\t%-20s\tSeparator",lineNo,yytext); }
"\n" 										{ lineNo++; }
%%
int main(int argc, char **argv)
{
    FILE *file;
    file=fopen("input.c","r");
    if(!file)
        {
            printf("could not open the file");
            exit(0);
        }
    yyin=file;
    yylex();
    printf("\n");
    return(0);
}
int yywrap()
{
    return(1);
}