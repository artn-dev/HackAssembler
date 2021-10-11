#ifndef HACK_PARSER_H
#define HACK_PARSER_H

#include <hack/tokens.h>
#include <hack/statement.h>

_HkTokenListNode *hkParseLiteral(_HkTokenListNode *token, HkStatement *statement);
_HkTokenListNode *hkParseBinaryOp(_HkTokenListNode *token, HkStatement *statement);
_HkTokenListNode *hkParseAssignment(_HkTokenListNode *token, HkStatement *statement);
_HkTokenListNode *hkParseJump(_HkTokenListNode *token, HkStatement *statement);

#endif /* HACK_PARSER_H */
