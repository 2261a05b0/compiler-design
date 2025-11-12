{ 
#include <stdio.h> 
#include <stdlib.h> 
int yylex(void); 
void yyerror(const char *s); 
%} 
%token ID NUM 
%% 
/* Grammar for simple arithmetic expressions */ 
E : T E1 '\n'        { printf("Parsing Successful! Expression is Valid.\n"); } 
; 
E1: '+' T E1 
| /* empty */ 
; 
T : F T1 
; 
T1: '*' F T1 
| /* empty */ 
; 
F : '(' E ')' 
| ID 
| NUM 
; 
%% 
int main() { 
printf("Enter the expression: "); 
yyparse(); 
return 0; 
} 
void yyerror(const char *s) { 
printf("Error: %s\n", s); 
}
