%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
%}

%option noyywrap   

%%
[^a-zA-Z\t\n ] {
    /* Reject any non-alphabetic character except whitespace */
    printf("Only alphabetic character '%c'\n", yytext[0]);
    exit(1);
}

\n {
    /* Stop processing on newline */
    printf("\n");
    exit(0);
}

. {
    /* Default rule: uppercase letters, preserve spacing */
    if (isalpha(yytext[0])) {
        printf("%c ", toupper(yytext[0]));
    }
    else {
        printf("  ");
    }
}
%%

int main() {
    yylex();   /* start scanner */
    return 0;
}