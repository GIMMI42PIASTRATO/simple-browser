#ifndef LEXER_H
#define LEXER_H

typedef struct Token Token;

Token *scanTokens(char *source);

#endif
