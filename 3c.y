{ 
#include <stdio.h> 
#include <stdlib.h> 
int yylex(); 
void yyerror(const char *s); 
%} 
%token NUM 
%left '+' '-' 
%left '*' '/' 
%% 
S : E { printf("Result = %d\n", $1); } 
; 
E : E '+' E { $$ = $1 + $3; } 
| E '-' E { $$ = $1 - $3; } 
| E '*' E { $$ = $1 * $3; } 
| E '/' E { $$ = $1 / $3; } 
| '(' E ')' { $$ = $2; } 
| NUM { $$ = $1; } 
; 
%% 
void yyerror(const char *s) { 
printf("Invalid expression\n"); 
} 
int main() { 
printf("Enter arithmetic expression: "); 
yyparse(); 
return 0; 
}
