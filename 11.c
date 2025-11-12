#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#define MAX 20 
char production[MAX][MAX]; 
char firstSet[10][10]; 
int n; 
void findFirst(char* result, char c); 
void addToResultSet(char* result, char val); 
int main() { 
int i; 
char result[10]; 
printf("Enter the number of productions: "); 
scanf("%d", &n); 
printf("Enter the productions (Example: E=E+T|T):\n"); 
for (i = 0; i < n; i++) { 
scanf("%s", production[i]); 
} 
for (i = 0; i < n; i++) { 
strcpy(result, ""); 
findFirst(result, production[i][0]); 
printf("FIRST(%c) = { %s }\n", production[i][0], result); 
} 
return 0; 
} 
void findFirst(char* result, char c) { 
int i, j, k; 
char subResult[20]; 
int foundEpsilon; 
// If c is terminal, FIRST(c) = c 
if (!isupper(c)) { 
addToResultSet(result, c); 
return; 
} 
// For each production rule 
for (i = 0; i < n; i++) { 
if (production[i][0] == c) { 
// If epsilon production 
if (production[i][2] == '#') { 
addToResultSet(result, '#'); 
} else { 
for (j = 2; j < strlen(production[i]); j++) { 
foundEpsilon = 0; 
strcpy(subResult, ""); 
findFirst(subResult, production[i][j]); 
for (k = 0; k < strlen(subResult); k++) { 
if (subResult[k] != '#') 
addToResultSet(result, subResult[k]); 
else 
foundEpsilon = 1; 
} 
if (!foundEpsilon) 
break; 
} 
} 
} 
}} 
void addToResultSet(char* result, char val) { 
for (int i = 0; i < strlen(result); i++) 
if (result[i] == val) 
return; // Avoid duplicates 
int len = strlen(result); 
result[len] = val; 
result[len + 1] = '\0'; 
}
