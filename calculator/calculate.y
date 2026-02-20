%{
#include <stdio.h>
#include <stdlib.h>

// Forward declarations
void yyerror(char *s);
int yylex();

// Global symbol table for single letters a-z, A-Z
int symbols[52];

int computeSymbolIndex(char symbl) {
    if (symbl >= 'a' && symbl <= 'z') return symbl - 'a';
    if (symbl >= 'A' && symbl <= 'Z') return symbl - 'A' + 26;
    return -1;
}

int SymbolVal(char symbl) {
    int index = computeSymbolIndex(symbl);
    return (index != -1) ? symbols[index] : 0;
}

void updateSymbolVal(char symbl, int val) {
    int index = computeSymbolIndex(symbl);
    if (index != -1) symbols[index] = val;
}
%}

%union {
    int num;
    char id;
}

%start line
%token print exiting
%token <num> number
%token <id> identifier
%type <num> line exp term
%type <id> assignment

%%
line : assignment ';'         { ; }

    | exiting                 { exit(0); }
    | print '(' exp ')' ';'   { printf("%d\n", $3); }
    | line assignment ';'     { ; }

    | line print '(' exp ')' ';' { printf("%d\n", $4); }
    | line exiting            { exit(0); }
    ;

assignment : identifier '=' exp { updateSymbolVal($1, $3); }
           ;

exp : exp '+' term  { $$ = $1 + $3; }

    | exp '-' term  { $$ = $1 - $3; }
    | term          { $$ = $1; }
    ;

term : number      { $$ = $1; }
     | identifier  { $$ = SymbolVal($1); }
     ;
%%

int main() {
    // Initialize array to zero
    for(int i=0; i<52; i++) symbols[i] = 0;
    
    printf("Enter your calculations:\n");
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
