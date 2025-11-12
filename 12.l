%{ 
#include "y.tab.h" 
%} 
%% 
[0-9]+
 [a-zA-Z]+
          { 
return NUM; } 
       { return ID; } 
"("             { return '('; } 
")"             { return ')'; } 
"*"
             { return '*'; } 
"+"             { return '+'; } 
\n              { return '\n'; }   /* Return newline to signal end of input */ 
[ \t]           ;                  /* Ignore spaces and tabs */ 
.               { return yytext[0]; } 
%%
int yywrap() { 
return 1; 
}
