#ifndef LEXER_H_
#define LEXER_H_

#include <stddef.h>
#include "./la.h"
#include "./free_glyph.h"

typedef enum {
    TOKEN_END = 0,
    TOKEN_SYMBOL,
    TOKEN_KEYWORD,
    TOKEN_GREATER,
    TOKEN_LOWER,
    TOKEN_DASH,
    TOKEN_OPEN_CURLY,
    TOKEN_CLOSE_CURLY,
    TOKEN_INVALID
} Token_Kind;

const char *token_kind_name(Token_Kind kind);

typedef struct {
    Token_Kind kind;
    const char *text;
    size_t text_len;
    Vec2f position;
} Token;

typedef struct {
    Free_Glyph_Atlas *atlas;
    const char *content;
    size_t content_len;
    size_t cursor;
    size_t line;
    size_t bol;
    float x;
} Lexer;

Lexer lexer_new(Free_Glyph_Atlas *atlas, const char *content, size_t content_len);
Token lexer_next(Lexer *l);

#endif // LEXER_H_
