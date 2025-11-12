%{ 
#include "y.tab.h" 
%} 
%% 
[0-9]+
                { yylval.string = strdup(yytext); return NUM; } 
[a-zA-Z][a-zA-Z0-9]*  { yylval.string = strdup(yytext); return ID; } 
[+\-*/()]   
          { return yytext[0]; } 
[\n]     
             { return 0; } 
[ \t]                 ; 
.                     ; 
%% 
int yywrap() { return 1; } 
