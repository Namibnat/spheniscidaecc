#include "spheniscidaecc.h"

char *source_code;

// static bool startwith...
// Note: I got this from chibicc
//       https://github.com/rui314/chibicc
static bool startswith(char *source, char *cmp_str){
	return strncmp(source, cmp_str, strlen(cmp_str)) == 0;
}

void tokenize(char *source){
	/* What are some initial things we're looking for:
	 * 	Skip spaces
	 * 	find combinations of letters, etc, that could be c
	 * 	find numbers
	 * 	look for the c words we know, such as main, int, return
	 * 	find semicolons
	 */
	while(*source){
		if(startswith(source, "int")){
			printf("<int>\n");
			source = source + strlen("int");
			continue;
		}
		if(startswith(source, "main")){
			printf("<main>\n");
			source = source + strlen("main");
			continue;
		}
		if(startswith(source, "return")){
			printf("<return>\n");
			source = source + strlen("return");
			continue;
		}
		if(startswith(source, ";")){
			printf("<;>\n");
			source++;
			continue;
		}
		if(startswith(source, "(")){
			printf("<(>\n");
			source++;
			continue;
		}
		if(startswith(source, ")")){
			printf("<)>\n");
			source++;
			continue;
		}
		if(startswith(source, "}")){
			printf("<}>\n");
			source++;
			continue;
		}
		if(startswith(source, "{")){
			printf("<{>\n");
			source++;
			continue;
		}
		if(isdigit(source[0])){
			printf("<");
			while(isdigit(source[0])){
				printf("%c", source[0]);
				source++;
			}
			printf(">\n");
			continue;
		}

		source++;
	}
	printf("\n");
}
