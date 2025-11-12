#include <stdio.h> 
#include <string.h> 
char input[100]; 
int i = 0; 
void E(); 
void Eprime(); 
void T(); 
void Tprime(); 
void F(); 
void error() { 
printf("\nError: Invalid expression\n"); 
exit(0); 
} 
void E() { 
T(); 
Eprime(); 
} 
void Eprime() { 
if (input[i] == '+') { 
I++; 
T(); 
Eprime(); 
} 
} 
void T() { 
F(); 
Tprime(); 
} 
void Tprime() { 
if (input[i] == '*') { 
i++; 
F(); 
Tprime(); 
} 
} 
void F() { 
if (input[i] == '(') { 
i++; 
E(); 
if (input[i] == ')') 
i++; 
else 
error(); 
} else if (input[i] == 'i' && input[i+1] == 'd') { 
i += 2; // match 'id' 
} else { 
error(); 
} 
} 
int main() { 
printf("Enter the expression: "); 
scanf("%s", input); 
E(); 
if (input[i] == '\0') 
printf("\nThe given expression is VALID.\n"); 
else 
printf("\nThe given expression is INVALID.\n"); 
return 0; 
}
