#include <hack/statement.h>


static void hkDeleteLiteral(HkStatement *statement)
{
        if (statement->value)
                free(statement->value);
}

static void hkDeleteBinaryOp(HkStatement *statement)
{
        if (statement->params == NULL)
                return;

        for (size_t i = 0; i < statement->paramCount; i++)
                hkDeleteStatement(statement->params + i);

        free(statement->params);
}

void hkDeleteStatement(HkStatement *statement)
{
        switch (statement->type) {
        case HK_ST_LITERAL:
                hkDeleteLiteral(statement);
                break;

        case HK_ST_BIN_OP:
	case HK_ST_ASSIGNMENT:
	case HK_ST_JUMP:
                hkDeleteBinaryOp(statement);
                break;
        }
}
