#include "tokens.h"


HkToken hkReadToken(FILE *file)
{
        HkToken token;
        token.type = HK_WHITESPACE;
        token.data = NULL;

        return token;
}
