Program: 
%{ 
#include<stdio.h> 
%} 
%% 
[a-zA-Z][a-zA-Z0-9]*   { printf("%s : Identifier\n", yytext); } 
[0-9]+
                 { printf("%s : Number\n", yytext); } 
"+"|"-"|"*"|"/"        { printf("%s : Operator\n", yytext); } 
.                      { /* ignore other characters */ } 
%% 
int main() { 
yylex(); 
return 0; 
} 
