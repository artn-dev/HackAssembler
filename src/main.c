#include <stdio.h>
#include <stdlib.h>
#include <hack/tokens.h>
#include <hack/statement.h>
#include <hack/parser.h>

#define BUFFER_SIZE 20


long int getEOF(FILE* file)
{
	fseek(file, 0, SEEK_END);
	long int eof = ftell(file);
	fseek(file, 0, SEEK_SET);
	return eof;
}

int main(int argc, char** argv)
{
	FILE* infile = fopen("programs/Test-Parser.asm", "r");

	if (infile == NULL) {
		printf("Error! Couldn't open file\n");
		exit(EXIT_FAILURE);
	}

	long int eof = getEOF(infile);
	HkToken *tokens = (HkToken*)malloc(BUFFER_SIZE * sizeof(HkToken));
	unsigned int tokenCount = 0;

	while (ftell(infile) != eof) {
		tokens[tokenCount] = hkReadToken(infile);
		tokenCount++;
	}
	tokens[tokenCount] = hkFinalToken();

	HkStatement *statements = (HkStatement*)malloc(BUFFER_SIZE * sizeof(HkStatement));
	HkToken *it = tokens;

	unsigned int statementCount = 0;
	while (it->type != HK_TK_END_OF_FILE) {
		it = hkParseAssignment(it, statements + statementCount);
		statementCount++;
	}

	// cleanup tokens
	for (unsigned int i = 0; i < tokenCount; i++) {
		if (tokens[i].data)
			free(tokens[i].data);
	}
	free(tokens);

	// cleanup statements
	for (unsigned int i = 0; i < statementCount; i++) {
		hkDeleteStatement(statements + i);
	}
	free(statements);

	fclose(infile);

	exit(EXIT_SUCCESS);
}
