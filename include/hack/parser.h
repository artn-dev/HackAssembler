#ifndef HACK_PARSER_H
#define HACK_PARSER_H

#include <hack/tokens.h>
#include <hack/statement.h>

_HkTokenListNode *hkParseLiteral(_HkTokenListNode *token, HkStatement *statement);

#endif /* HACK_PARSER_H */