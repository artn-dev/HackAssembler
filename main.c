#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

long int getEOF(FILE* file)
{
	fseek(file, 0, SEEK_END);
	long int eof = ftell(file);
	fseek(file, 0, SEEK_SET);
	return eof;
}

int main(int argc, char** argv)
{
	FILE* infile = fopen("programs/Add.asm", "r");

	if (infile == NULL) {
		printf("Error! Couldn't open file\n");
		exit(EXIT_FAILURE);
	}

	long int eof = getEOF(infile);
	while (ftell(infile) != eof) {
		HkToken token = hkReadToken(infile);

		if (token.data != NULL) {
			printf("Read: %s\n", token.data);
			// prevent memory leaks during testing
			free(token.data);
		}
	}

	fclose(infile);
	exit(EXIT_SUCCESS);
}
