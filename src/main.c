#include <stdio.h>
#include <stdlib.h>
#include <hack/tokens.h>
#include <hack/statement.h>
#include <hack/parser.h>

#define BUFFER_SIZE 20


static HkToken *cleanupTokens(HkToken *tokens, unsigned long count);
static HkStatement *cleanupStatements(HkStatement *statements, unsigned long count);
static long int getEOF(FILE* file);


int main(int argc, char** argv)
{
	FILE* infile = fopen("programs/Test-Parser.asm", "r");

	if (infile == NULL) {
		printf("Error! Couldn't open file\n");
		exit(EXIT_FAILURE);
	}

	long int eof = getEOF(infile);

	HkToken *tokens = (HkToken*)malloc(BUFFER_SIZE * sizeof(HkToken));
	unsigned long tokenCount = 0;

	while (ftell(infile) != eof) {
		tokens[tokenCount] = hkReadToken(infile);
		tokenCount++;
	}
	tokens[tokenCount] = hkFinalToken();

	HkStatement *statements = (HkStatement*)malloc(BUFFER_SIZE * sizeof(HkStatement));
	unsigned long statementCount = 0;

	HkToken *it = tokens;
	while (it->type != HK_TK_END_OF_FILE) {
		it = hkParseAssignment(it, statements + statementCount);
		statementCount++;
	}

	tokens = cleanupTokens(tokens, tokenCount);
	statements = cleanupStatements(statements, statementCount);
	fclose(infile);

	exit(EXIT_SUCCESS);
}


HkToken *cleanupTokens(HkToken *tokens, unsigned long count)
{
	for (unsigned int i = 0; i < count; i++) {
		if (tokens[i].data)
			free(tokens[i].data);
	}
	free(tokens);
	return NULL;
}

HkStatement *cleanupStatements(HkStatement *statements, unsigned long count)
{
	for (unsigned int i = 0; i < count; i++) {
		hkDeleteStatement(statements + i);
	}
	free(statements);
	return NULL;
}

long int getEOF(FILE* file)
{
	fseek(file, 0, SEEK_END);
	long int eof = ftell(file);
	fseek(file, 0, SEEK_SET);
	return eof;
}