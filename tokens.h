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

/**
 * Node of a linked list of tokens.
 */
typedef struct _HkTokenListNode {
        _HkTokenListNode *next;
        HkToken data;
} _HkTokenListNode; 

/**
 * Linked list of tokens.
 * This lists holds the tokens found by the program. All it's
 * operations are to be made with helper functions.
 */
typedef struct HkTokenList {
        _HkTokenListNode *head; /*< First token in list */
        _HkTokenListNode *tail; /*< Last token in list */
} HkTokenList;


/**
 * Creates list of tokens.
 * Creates and initializes a instance of 'HkTokenList'.
 * @see HkTokenList
 * @return a instance of 'HkTokenList'
 */
HkTokenList hkCreateTokenList();

HkToken hkReadToken(FILE *file);

#endif /* HACK_TOKENS_H */