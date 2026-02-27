%{
    #include <stdio.h>  // Include standard I/O for printing tokens
%}

DIGIT     [0-9]
NUMBER    {DIGIT}+(\.{DIGIT}+)?  
LETTER    [a-zA-Z]
NON_ASCII [^\x00-\x7F]
WORD      ({LETTER}|{NON_ASCII})+

%%
is |
am |
are |
can |
could |
run |
ride |
eat |
sleep |
read  |
walk |
bought |
talk |
laugh |
cry                  { printf("VERB(%s)\n", yytext); }
{NUMBER}             { printf("NUMBER(%s)\n", yytext); }
{WORD}                 { printf("NOT-VERB(%s)\n", yytext); }
[ \t]                { /* Ignore whitespace */ }
.                    { printf("%s\n", yytext); }  /* Matches single-byte chars like . */
%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
