#include "spheniscidaecc.h"

char *source_code;
int counter = 0;
char tmp_name[32];

// static bool startwith...
// Note: I got this from chibicc
//       https://github.com/rui314/chibicc
static bool startswith(char *source, char *cmp_str){
	return strncmp(source, cmp_str, strlen(cmp_str)) == 0;
}

static bool is_viable_first_char(char c){
	return ((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')
			|| (c == '_'));
}

static bool is_viable_variable_char(char c){
	return ((is_viable_first_char(c))
			|| isdigit(c));
}

void tokenize(char *source){
							
	char *max_var_len_error = "Variable must be less than 31 characters\n";

	while(*source){
		if(is_viable_first_char(source[0])){
			while (is_viable_variable_char(source[0])){
				printf("%c", source[0]);
				source++;
				counter++;
				if (counter > MAX_VAR_LENGTH){
					// 31 characters long:
					// ............................... 
					fputs(max_var_len_error, stderr);
					exit(1);
				}
			}
			printf("\n");
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
