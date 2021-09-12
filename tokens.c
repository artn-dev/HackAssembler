#include "tokens.h"


HkToken hkReadToken(FILE *file)
{
        HkToken token;
        token.type = HK_WHITESPACE;
        token.data = NULL;

        char currCh = fgetc(file);

        switch (currCh) {
        case '/':
                do {
                        currCh = fgetc(file);
                } while (currCh != '\n' && currCh != '\r' && currCh != EOF);
                break;
        }

        return token;
}
