#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX 10 
struct StackFrame { 
char funcName[20]; 
int localVar[5]; 
}; 
struct StackFrame stack[MAX]; 
int top = -1; 
void push(char *fname) { 
if (top == MAX - 1) { 
printf("Stack Overflow - No more space for function calls.\n"); 
Return; 
} 
top++; 
strcpy(stack[top].funcName, fname); 
printf("Function %s() called. Memory allocated on stack.\n", fname); 
Prepared by P Poornima, Assistant Professor, Dept of CSE, MGIT. 
Compiler Design Lab Manual                                                                                        
26 
} 
void pop() { 
if (top == -1) { 
printf("Stack Underflow - No active function.\n"); 
return; 
} 
printf("Function %s() exited. Memory deallocated from stack.\n", 
stack[top].funcName); 
top--; 
} 
void display() { 
if (top == -1) { 
printf("Stack is empty.\n"); 
return; 
} 
printf("\nCurrent Stack Frames:\n"); 
for (int i = top; i >= 0; i--) 
printf("-> %s()\n", stack[i].funcName); 
} 
int main() { 
int choice; 
char fname[20]; 
while (1) { 
printf("\n--- STACK ALLOCATION MENU ---\n"); 
printf("1. Function Call (Push)\n"); 
printf("2. Function Return (Pop)\n"); 
printf("3. Display Stack\n"); 
printf("4. Exit\n"); 
printf("Enter choice: ");         
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter function name: "); 
scanf("%s", fname); 
push(fname); 
break; 
case 2: 
pop(); 
break; 
case 3: 
display(); 
break; 
case 4: 
exit(0); 
default: 
printf("Invalid choice!\n"); 
} 
} 
return 0; 
} 
