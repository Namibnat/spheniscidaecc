
#include <stdio.h>
#include <string.h>   // for strlen
#include <stdlib.h>
#include <stdbool.h>  // for bool, used in tokenize
#include <ctype.h>    // for isdigit

void tokenize(char *source);
						
#define MAX_VAR_LENGTH 31

typedef struct TOKEN {
	char identifier[32];
};

TOKEN *tokstream;
