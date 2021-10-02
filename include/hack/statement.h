#ifndef HACK_STATEMENT_H
#define HACK_STATEMENT_H


/**
 * Represents different types of statements.
 */
enum HkStatementType {
        HK_ST_LITERAL,
        HK_ST_BIN_OP,
};

/**
 * Represents a statement.
 * This struct can be used to make a syntax tree based
 * on the statement type and its parameters.
 */
typedef struct HkStatement {
        /**
         * Statement's type.
         * @see HkStatementType
         */
        enum HkStatementType type;       

        /**
         * Represents the data related to different statements.
         */
        union{
                char *value;
                struct {
                        struct HkStatement *params;
                        size_t paramCount;
                };
        };
} HkStatement;

#endif /* HACK_STATEMENT_H */