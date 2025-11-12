#include <stdio.h> 
#include <stdbool.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
bool isDelimiter(char chr) { 
return (chr == ' ' || chr == '+' || chr == '-' || chr == '*' || 
chr == '/' || chr == ',' || chr == ';' || chr == '%' || 
chr == '>' || chr == '<' || chr == '=' || chr == '(' || 
chr == ')' || chr == '[' || chr == ']' || chr == '{' || chr == '}'); 
} 
bool isOperator(char chr) { 
return (chr == '+' || chr == '-' || chr == '*' || chr == '/' || 
chr == '>' || chr == '<' || chr == '='); 
} 
bool isKeyword(char *str) { 
const char *keywords[] = { 
"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", 
"enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", 
"short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", 
"unsigned", "void", "volatile", "while" 
}; 
int n = sizeof(keywords) / sizeof(keywords[0]); 
for (int i = 0; i < n; i++) { 
if (strcmp(str, keywords[i]) == 0) { 
return true; 
} 
Prepared by P Poornima, Assistant Professor, Dept of CSE, MGIT. 
Compiler Design Lab Manual                                                                                        
34 
} 
return false; 
} 
bool isInteger(char *str) { 
for (int i = 0; str[i] != '\0'; i++) { 
if (!isdigit(str[i])) 
return false; 
} 
return true; 
} 
bool isValidIdentifier(char *str) { 
if (!(isalpha(str[0]) || str[0] == '_')) 
return false; 
for (int i = 1; str[i] != '\0'; i++) { 
if (!(isalnum(str[i]) || str[i] == '_')) 
return false; 
} 
return true; 
} 
char* getSubstring(char* str, int start, int end) { 
int length = end - start + 1; 
char* subStr = (char*)malloc((length + 1) * sizeof(char)); 
strncpy(subStr, str + start, length); 
subStr[length] = '\0'; 
return subStr; 
} 
void lexicalAnalyzer(char* input) { 
int left = 0, right = 0; 
int length = strlen(input); 
while (right <= length && left <= right) { 
if (!isDelimiter(input[right])) 
right++; 
if (isDelimiter(input[right]) && left == right) { 
if (isOperator(input[right])) 
printf("Token: Operator, Value: %c\n", input[right]); 
right++; 
left = right; 
} 
else if ((isDelimiter(input[right]) && left != right) || (right == length && left != 
right)) { 
char* subStr = getSubstring(input, left, right - 1); 
if (isKeyword(subStr)) 
printf("Token: Keyword, Value: %s\n", subStr); 
else if (isInteger(subStr)) 
printf("Token: Constant, Value: %s\n", subStr); 
else if (isValidIdentifier(subStr)) 
printf("Token: Identifier, Value: %s\n", subStr); 
else 
printf("Token: Unknown, Value: %s\n", subStr); 
free(subStr); 
left = right; 
} 
} 
} 
int main() { 
char input[500]; 
printf("Enter source code line:\n"); 
fgets(input, sizeof(input), stdin); 
// Remove trailing newline from input if present 
size_t len = strlen(input); 
if (len > 0 && input[len - 1] == '\n') 
input[len - 1] = '\0'; 
printf("\nAnalyzing tokens:\n"); 
lexicalAnalyzer(input); 
return 0; 
}
