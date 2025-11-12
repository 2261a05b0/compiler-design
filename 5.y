%{ 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
int yylex(); 
void yyerror(const char *s); 
typedef struct { 
char name[20]; 
char type[10]; 
} Symbol; 
Symbol table[20]; 
int count = 0; 
void addToTable(char *name, char *type) { 
strcpy(table[count].name, name); 
strcpy(table[count].type, type); 
count++; 
} 
char* getType(char *name) { 
for (int i = 0; i < count; i++) { 
if (strcmp(table[i].name, name) == 0) 
return table[i].type; 
} 
return "undef"; 
} 
%} 
%union { 
char *string; 
} 
%token <string> ID NUM TYPE 
%type <string> E 
%left '+' '-' 
%left '*' '/' 
%% 
S : DECLS STMTS { printf("Type checking completed successfully.\n"); } 
; 
DECLS : DECLS DECL 
| DECL 
; 
DECL : TYPE ID ';'  { addToTable($2, $1); } 
; 
STMTS : STMTS STMT 
| STMT 
; 
STMT : ID '=' E ';' { 
char *lhsType = getType($1); 
if (strcmp(lhsType, "undef") == 0) 
printf("Error: Variable %s not declared.\n", $1); 
else if (strcmp(lhsType, $3) != 0) 
printf("Type Mismatch: %s = %s\n", lhsType, $3); 
else 
printf("Assignment valid: %s = %s\n", $1, $3); 
} 
; 
E : E '+' E { if(strcmp($1,$3)==0) $$=$1; else $$="float"; } 
| E '-' E { if(strcmp($1,$3)==0) $$=$1; else $$="float"; } 
| E '*' E { if(strcmp($1,$3)==0) $$=$1; else $$="float"; } 
| E '/' E { $$="float"; } 
| ID      { $$ = getType($1); } 
| NUM     { $$ = "int"; } 
; 
%% 
void yyerror(const char *s) { 
printf("Error: %s\n", s); 
} 
int main() { 
printf("Enter declarations and statements:\n"); 
yyparse(); 
return 0; 
} 
