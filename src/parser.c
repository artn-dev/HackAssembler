#include <hack/parser.h>


_HkTokenListNode *hkParseLiteral(_HkTokenListNode *token, HkStatement *statement)
{
        if (token->data.type == HK_TK_IDENTIFIER) {
                statement->type = HK_ST_LITERAL;
                statement->value = token->data.data;
        }
        return token->next;
}