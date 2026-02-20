%{
#include "calculate.tab.h"
void yyerror(char *s);
%}

%%
"print"     { return print; }
"exiting"   { return exiting; }
[0-9]+      { yylval.num = atoi(yytext); return number; }
[a-zA-Z]    { yylval.id = yytext[0]; return identifier; }
[ \t\n]     { ; }
[+\-=();]   { return yytext[0]; }
.           { yyerror("Unknown character"); }
%%

int yywrap() {
    return 1;
}
