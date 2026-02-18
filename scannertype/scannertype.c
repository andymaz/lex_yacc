#include <stdio.h>
#include "scannertype.h"   // Contains token definitions

// Flex-generated lexer functions and variables
extern int yylex();        // Function that returns the next token
extern int yylineno;       // Current line number in input
extern char* yytext;       // Text of the current token

// Convert token numbers to readable strings
char *tokenTypeToString(int token) {
    switch (token) {
        case TYPE: return "TYPE";
        case NAME: return "NAME";
        case TABLE_PREFIX: return "TABLE_PREFIX";
        case PORT: return "PORT";
        case COLON: return "COLON";
        case IDENTIFIER: return "IDENTIFIER";
        case INTEGER: return "INTEGER";
        default: return "UNKNOWN"; // Fallback for unrecognized tokens
    }
}

int main() {
    int token;

    // Loop over tokens until yylex() returns 0 (EOF)
    while ((token = yylex()) != 0) {
        // Print token number, line number, and matched text
        printf("Token: %d, Line: %d, Text: %s\n", token, yylineno, yytext);
        // Optional: use tokenTypeToString(token) for more readable output
        // printf("Token: %s, Line: %d, Text: %s\n", tokenTypeToString(token), yylineno, yytext);
    }

    return 0; // Successful execution
}
