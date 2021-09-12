#include "tokens.h"
#include <string.h>
#include <stdlib.h>

#define isdigit(x) ('0' <= (x) && (x) <= '9')
#define isalpha(x) (('a' <= (x) && (x) <= 'z') || ('A' <= (x) && (x) <= 'Z'))


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

        case '\n':
        case '\r':
                token.type = HK_END_OF_STATEMENT;
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

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
                token.type = HK_INTEGER_LITERAL;

                // find number of digits
                long int digitCount = 0;
                do {
                        ++digitCount;
                        currCh = fgetc(file);
                } while (isdigit(currCh));

                // allocate memory in string
                token.data = (char*)malloc(digitCount + 1);

                // return to beginning of number
                long int offset = (currCh == EOF) ? 0 : 1;
                fseek(file, -digitCount - offset, SEEK_CUR);

                // read digits
                fread(token.data, sizeof(char), digitCount, file);
                }
                break;

        default: {
                if (!(isalpha(currCh) || currCh == '_'))
                        break;

                token.type = HK_IDENTIFIER;

                // find number of characters
                long int charCount = 0;
                do {
                        ++charCount;
                        currCh = fgetc(file);
                } while (isalpha(currCh) || isdigit(currCh) || currCh == '_');

                // allocate memory in string
                token.data = (char*)malloc(charCount + 1);

                // return to beginning of number
                long int offset = (currCh == EOF) ? 0 : 1;
                fseek(file, -charCount - offset, SEEK_CUR);

                // read digits
                fread(token.data, sizeof(char), charCount, file);
                }
        }

        return token;
}
