// Lex Program to find the longest word and its length in a text file
%{
	#include<stdio.h>
	#include<string.h>
	int longest = 0;
	int x=0;
	char longWord[20][100];
%}

/* Rule Section */
%%
	[a-zA-Z]+  { 
		if(yyleng > longest){
			x=0;
			longest = yyleng;
			strcpy(longWord[x++],yytext);

		}
		else if(yyleng == longest){   
			strcpy(longWord[x++],yytext);
		}
	}
%%

int main(){
	yyin = fopen("input.txt","r");
	yylex();

	printf("Longest length : %d\n",longest);
	printf("Longest word :\n");

	int i =0;
	while(i < x) {
		printf("%s\n", longWord[i]);
		i++;
	}

	return 0;
}


int yywrap()
{ 
	return 1;
}

