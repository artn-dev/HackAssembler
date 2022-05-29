#include <hack/parser.h>
#include <stdlib.h>


HkToken *hkParseLiteral(HkToken *token, HkStatement *statement)
{
        if (token->type == HK_TK_IDENTIFIER) {
                statement->type = HK_ST_LITERAL;
                statement->value = token->data;
                token->data = NULL;
        }
        return token + 1;
}

HkToken *hkParseBinaryOp(HkToken *token, HkStatement *statement)
{
        statement->type = HK_ST_BIN_OP;
        statement->paramCount = 2;
        statement->params = (HkStatement*)malloc(2 * sizeof(HkStatement));

	token = hkParseLiteral(token, statement->params + 0);
	token = hkParseLiteral(token + 1, statement->params + 1);

	return token;
}

HkToken *hkParseAssignment(HkToken *token, HkStatement *statement)
{
	HkStatement lhs;
	token = hkParseLiteral(token, &lhs);

        if (token == NULL || token->type == HK_TK_END_OF_STATEMENT) {
                *statement = lhs;
                return token;
        }

        statement->type = HK_ST_ASSIGNMENT;
        statement->paramCount = 2;
        statement->params = (HkStatement*)malloc(2 * sizeof(HkStatement));

        statement->params[0] = lhs;
        token = hkParseJump(token + 1, statement->params + 1);

        return token;
}

HkToken *hkParseJump(HkToken *token, HkStatement *statement)
{
        statement->type = HK_ST_JUMP;
        statement->paramCount = 2;
        statement->params = (HkStatement*)malloc(2 * sizeof(HkStatement));

        token = hkParseBinaryOp(token, statement->params + 0);
        if (token->type != HK_TK_END_OF_STATEMENT)
                token = hkParseLiteral(token + 1, statement->params + 1);

        return token + 1;
}
