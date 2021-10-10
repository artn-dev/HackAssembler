#include <hack/parser.h>
#include <stdlib.h>


_HkTokenListNode *hkParseLiteral(_HkTokenListNode *token, HkStatement *statement)
{
        if (token->data.type == HK_TK_IDENTIFIER) {
                statement->type = HK_ST_LITERAL;
                statement->value = token->data.data;
                token->data.data = NULL;
        }
        return token->next;
}

_HkTokenListNode *hkParseBinaryOp(_HkTokenListNode *token, HkStatement *statement)
{
        statement->type = HK_ST_BIN_OP;
        statement->paramCount = 2;
        statement->params = (HkStatement*)malloc(2 * sizeof(HkStatement));

	token = hkParseLiteral(token, statement->params + 0);
	token = hkParseLiteral(token->next, statement->params + 1);

	return token;
}

_HkTokenListNode *hkParseAssignment(_HkTokenListNode *token, HkStatement *statement)
{
	HkStatement lhs;
	token = hkParseLiteral(token, &lhs);

        if (token == NULL || token->data.type == HK_TK_END_OF_STATEMENT) {
                *statement = lhs;
                return token;
        }

        statement->type = HK_ST_ASSIGNMENT;
        statement->paramCount = 2;
        statement->params = (HkStatement*)malloc(2 * sizeof(HkStatement));

        statement->params[0] = lhs;
        token = hkParseBinaryOp(token->next, statement->params + 1);

        return token;
}
