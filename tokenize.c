#include "spheniscidaecc.h"

char *source_code;
int counter = 0;
char tmp_name[32];

extern Token *tokstream;

// static bool startswith... - I got this from chibicc
//       https://github.com/rui314/chibicc
static bool startswith(char *source, char *cmp_str) {
	return strncmp(source, cmp_str, strlen(cmp_str)) == 0;
}

static bool is_viable_first_char(char c) {
	return ((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')
			|| (c == '_'));
}

static bool is_viable_variable_char(char c) {
	return ((is_viable_first_char(c))
			|| isdigit(c));
}

static void addtoken(int tn, char *id, TokenKind k, size_t used){
	/*
	typedef enum {
		TK_DTYPE, // c datatype
		TK_OTHER, // placeholder for now
	} TokenKind;

	typedef struct Token Token;
	struct Token {
		int token_num;
		char identifier[32];
		TokenKind kind;
		size_t used;
	};
	 * */
	// Token* tokenstream = 
	printf("Token %d, %s\n", tn, id);
}

void tokenize(){
	extern char *source;
	extern int token_counter;
	token_counter = 0;
							
	char *max_var_len_error = "Variable must be less than 31 characters\n";
	char *cdatatypes[] = {"char", "int", "float", "double",
		"short int", "long int", "long double"};
	int got, i;

	while(*source) {
		got = 0;
		/* reserved words in C that we want to deal with:
		 * 	_Bool, _Complex, _Imaginary, auto, break, case, char, const,
		 * 	continue, default, do, double, else, enum, extern, float, 
		 * 	for, goto, if, inline, int, long, register, restrict, 
		 * 	return, short, signed, sizeof, static, struct, switch,
		 * 	typedef, union, unsigned, void, volatile, while */

		/* check data types */
		i = 0;
		for(; i < 7; i++){
			if(startswith(source, cdatatypes[i])) {
				printf("<%s>: type: datatype\n", cdatatypes[i]);
				source = source + strlen(cdatatypes[i]);
				got++;
				break;
			}
		}
		if(got){
			addtoken(token_counter, cdatatypes[i], TK_DTYPE, 0);
			token_counter++;
			continue;
		}
		if(is_viable_first_char(source[0])) {
			while (is_viable_variable_char(source[0])) {
				printf("%c", source[0]);
				source++;
				counter++;
				if (counter > MAX_VAR_LENGTH) {
					// 31 characters long:
					// ............................... 
					fputs(max_var_len_error, stderr);
					exit(1);
				}
			}
			printf("\n");
			token_counter++;
			continue;
		}
		if(startswith(source, ";")) {
			printf("<;>\n");
			source++;
			token_counter++;
			continue;
		}
		if(startswith(source, "(")) {
			printf("<(>\n");
			source++;
			token_counter++;
			continue;
		}
		if(startswith(source, ")")) {
			printf("<)>\n");
			source++;
			token_counter++;
			continue;
		}
		if(startswith(source, "}")) {
			printf("<}>\n");
			source++;
			token_counter++;
			continue;
		}
		if(startswith(source, "{")) {
			printf("<{>\n");
			source++;
			token_counter++;
			continue;
		}
		if(isdigit(source[0])) {
			printf("<");
			while(isdigit(source[0])) {
				printf("%c", source[0]);
				source++;
			}
			printf(">\n");
			token_counter++;
			continue;
		}

		source++;
	}
	printf("\n");
}
