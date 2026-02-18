%{
#include "parser.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[ \t]       ; /* skip whitespace */
\n          { return EOL; }
.           { return yytext[0]; }
%%

int yywrap() { return 1; }
