%{ 
int yylex(void); 
#include <stdio.h> 
#include <stdlib.h> 
void yyerror(const char *s); 
/*E->E+E/E*E/(E)/DIGIT*/ 
%} 
%union 
{ 
int dval; 
} 
%token <dval> DIGIT 
%type <dval> expr 
%type <dval> term 
%type <dval> factor 
%% 
line:expr '\n' {printf("%d",$1);exit(0);} 
; 
expr:expr '+' term {$$=$1+$3;} 
|term 
; 
term:term '*' factor {$$=$1*$3;} 
|factor 
; 
factor: '(' expr ')' {$$=$2;} 
|DIGIT 
; 
%% 
int main() 
{ 
yyparse(); 
} 
void yyerror(const char *s) { 
printf("Invalid Expression\n"); 
} 
LEX Program (arith.l): 
{ 
#include<stdio.h> 
#include "y.tab.h" 
%} 
%% 
[0-9]+ {yylval.dval=atoi(yytext); return DIGIT;} 
\n|. return yytext[0]; 
%%
