%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char const *s);
int yylex(void);
%}

%token NUMBER EOL
%left '+' '-'
%left '*' '/'

%%
calc: 
    | calc expr EOL { printf("= %d\n", $2); }
    ;

expr: NUMBER        { $$ = $1; }
    | expr '+' expr { $$ = $1 + $3; }
    | expr '-' expr { $$ = $1 - $3; }
    | expr '*' expr { $$ = $1 * $3; }
    | expr '/' expr { 
        if ($3 == 0) { yyerror("divide by zero"); $$ = 0; }
        else { $$ = $1 / $3; }
    }
    | '(' expr ')'  { $$ = $2; }
    ;
%%

void yyerror(char const *s) { fprintf(stderr, "error: %s\n", s); }

int main() {
    printf("Enter expression:\n");
    return yyparse();
}
