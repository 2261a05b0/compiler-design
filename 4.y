%{ 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct node { 
char *token; 
struct node *left, *right; 
}; 
struct node* createNode(char *token, struct node *left, struct node *right); 
void printTree(struct node *tree, int level); 
int yylex(); 
void yyerror(const char *s); 
struct node *root = NULL;  // Global root 
%} 
%union { 
struct node *node; 
char *string; 
} 
%token <string> ID NUM 
%type <node> E T F 
%left '+' '-' 
%left '*' '/' 
%% 
input : E { root = $1; }  
; 
E : E '+' T   { $$ = createNode("+", $1, $3); } 
| E '-' T   { $$ = createNode("-", $1, $3); } 
| T         { $$ = $1; } 
; 
T : T '*' F   { $$ = createNode("*", $1, $3); } 
| T '/' F   { $$ = createNode("/", $1, $3); } 
| F
         { $$ = $1; } 
; 
F : '(' E ')' { $$ = $2; } 
| ID
        { $$ = createNode($1, NULL, NULL); } 
| NUM       { $$ = createNode($1, NULL, NULL); } 
; 
%% 
struct node* createNode(char *token, struct node *left, struct node *right) { 
struct node *newNode = (struct node*)malloc(sizeof(struct node)); 
newNode->token = strdup(token); 
newNode->left = left; 
newNode->right = right; 
return newNode; 
} 
void printTree(struct node *tree, int level) { 
if (tree == NULL) return; 
printTree(tree->right, level + 1); 
for (int i = 0; i < level; i++) printf("    "); 
printf("%s\n", tree->token); 
printTree(tree->left, level + 1); 
} 
void yyerror(const char *s) { 
printf("Error: %s\n", s); 
} 
int main() { 
printf("Enter expression: "); 
if (yyparse() == 0 && root != NULL) { 
printf("\nAbstract Syntax Tree:\n"); 
printTree(root, 0); 
} else { 
printf("Error parsing expression.\n"); 
} 
return 0; 
}
