#include "spheniscidaecc.h"

#define ISSPACE 1
#define ISNOTSPACE 0

char *source_code;

int is_space_char(char c){
	switch(c){
		case ' ':
			return ISSPACE;
			break;
		case '\n':
			return ISSPACE;
			break;
		case '\t':
			return ISSPACE;
			break;
		default:
			return ISNOTSPACE;
	}
}

void tokenize(char *source){
	char intoken = 1;
	for (size_t i = 0; i < strlen(source); i++){
		if(is_space_char(source[i])){
			intoken = 0;
			printf("; ");
		}
		else{
			intoken = 1;
			putchar(source[i]);
		}
	}
	printf("\n");
}
