%{ 
#include <stdio.h> 
int wordCount = 0, lineCount = 0; 
%} 
%% 
[a-zA-Z]+    { wordCount++; }          /* Increment word count for each word */ 
\n           { lineCount++; }          /* Increment line count for each new line */ 
.            { }                       /* Ignore other characters */ 
%% 
int main() { 
printf("Enter the text (Press Ctrl+D to end):\n"); 
yylex();  // Start lexical analysis 
printf("\nTotal number of words: %d\n", wordCount); 
printf("Total number of lines: %d\n", lineCount); 
return 0; 
} 
