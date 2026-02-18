%{
#include "scannertype.h"    
%}
/* line number tracking */
%option yylineno
%%
:                       return COLON;  
"db_type"               return TYPE;
"db_name"               return NAME;
"db_table_prefix"       return TABLE_PREFIX;
"db_port"               return PORT;
[a-zA-Z_][a-zA-Z0-9_]*  return IDENTIFIER;
[0-9]+                  return NUMBER;
[ \t\n]+                ; /* ignore whitespace */    
.                       printf("Unexpected character: %c\n", yytext[0]);       
%%
int yywrap(void) {
    return 1; // Tell Flex there’s no more input (EOF)
}