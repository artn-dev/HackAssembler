#include "tokens.h"
#include <string.h>
#include <stdlib.h>


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

        case '@':
        case '+':
        case '=':
        case '-':
        case '!':
        case '&':
        case '|':
        case ';':
                token.type = HK_OPERATOR;
                token.data = (char*)malloc(2);
                token.data[0] = currCh;
                token.data[1] = '\0';
                break;
        }

        return token;
}
