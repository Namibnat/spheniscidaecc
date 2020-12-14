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
		if(startswith(source, "main")){
			printf("<main>\n");
			while(!startswith(source, "(")){
				source++;
			continue;
			}
		}
		source++;
	}
	printf("\n");
}
