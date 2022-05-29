#ifndef HACK_TOKENS_H
#define HACK_TOKENS_H

#include <stdio.h>


/**
 * Represents the differents types of tokens.
 */
enum HkTokenType {
        HK_TK_WHITESPACE,
        HK_TK_OPERATOR,
        HK_TK_INTEGER_LITERAL,
        HK_TK_IDENTIFIER,
        HK_TK_END_OF_STATEMENT,
};

/**
 * Represents a token.
 * The token assigns a group of characters read from a file to a type of
 * object recognizable by the parser.
 */
typedef struct HkToken {
        /**
         * The token's type.
         * A object type recognizable by the parser.
         * @see HkTokenType
         */
        enum HkTokenType type;

        /**
         * The token's value.
         * A group of characters read from a file.
         */
        char *data;
} HkToken;


HkToken hkReadToken(FILE *file);

#endif /* HACK_TOKENS_H */
