#ifndef HACK_PARSER_H
#define HACK_PARSER_H

#include <hack/tokens.h>
#include <hack/statement.h>

HkToken *hkParseLiteral(HkToken *token, HkStatement *statement);
HkToken *hkParseBinaryOp(HkToken *token, HkStatement *statement);
HkToken *hkParseAssignment(HkToken *token, HkStatement *statement);
HkToken *hkParseJump(HkToken *token, HkStatement *statement);

#endif /* HACK_PARSER_H */
