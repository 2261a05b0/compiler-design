#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
char input[100]; 
int i = 0; 
void S(); 
void L(); 
void Lprime(); 
void error(); 
void error() { 
printf("\nError: Invalid expression!\n"); 
exit(0); 
} 
void S() { 
if (input[i] == '(') { 
i++; 
L(); 
if (input[i] == ')') 
i++; 
else 
error(); 
} else if (input[i] == 'a') { 
i++; 
} else { 
error(); 
} 
} 
void L() { 
S(); 
Lprime(); 
} 
void Lprime() { 
if (input[i] == ',') { 
i++; 
S(); 
Lprime(); 
}  
} 
int main() { 
printf("Enter the expression: "); 
scanf("%s", input); 
S(); 
if (input[i] == '\0') 
printf("\nThe given expression is VALID.\n"); 
else 
printf("\nThe given expression is INVALID.\n"); 
return 0; 
}
