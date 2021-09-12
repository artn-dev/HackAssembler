#ifndef HACK_TOKENS_H
#define HACK_TOKENS_H

#include <stdio.h>


/**
 * Represents the differents types of tokens.
 */
enum HkTokenType {
        HK_WHITESPACE,
        HK_OPERATOR,
        HK_INTEGER_LITERAL,
        HK_IDENTIFIER,
        HK_END_OF_STATEMENT,
};

/**
 * Represents a token.
 * The token assigns a group of characters read from a file to a type of
 * object recognizable by the parser.
 */
struct HkToken_t {
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
};

typedef struct HkToken_t HkToken;


HkToken hkReadToken(FILE *file);

#endif /* HACK_TOKENS_H */