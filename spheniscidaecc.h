
#include <stdio.h>
#include <string.h>   // for strlen
#include <stdlib.h>
#include <stdbool.h>  // for bool, used in tokenize
#include <ctype.h>    // for isdigit

/*
 * tokenize.c
 */

void tokenize(char *source);
						
#define MAX_VAR_LENGTH 31

typedef enum {
	TK_DTYPE, // c datatype
	TK_OTHER, // placeholder for now
} TokenKind;

typedef struct TOKEN TOKEN;
struct TOKEN {
	char identifier[32];
	TokenKind kind;
};

TOKEN *tokstream;

