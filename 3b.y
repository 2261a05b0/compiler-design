%{ 
#include <stdio.h> 
int yylex(); 
void yyerror(const char *s); 
%} 
%token ID 
%% 
S : ID { printf("Valid variable name\n"); } 
; 
%% 
void yyerror(const char *s) { 
printf("Invalid variable name\n"); 
} 
int main() { 
printf("Enter variable: "); 
yyparse(); 
return 0; 
}
