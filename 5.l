%{ 
#include "y.tab.h" 
%} 
%% 
"int"
 "float"
 [0-9]+
       { yylval.string = "int"; return TYPE; } 
     { yylval.string = "float"; return TYPE; } 
      { yylval.string = "int"; return NUM; } 
[a-zA-Z][a-zA-Z0-9]* { yylval.string = strdup(yytext); return ID; } 
"="         { return '='; } 
";"         { return ';'; } 
[+\-*/]     { return yytext[0]; } 
[\n\t ]     ; 
.           ; 
%% 
int yywrap() 
{ 
return 1; 
} 
