/* The compiler */

#include <stdio.h>
#include <string.h> // for strlen
#include <stdlib.h>

char *source_code;

static void tokenize(char *source){
	for (size_t i; i < strlen(source); i++){
		printf("mysource[%lu] = %c\n", i, source[i]);
	}
}

static void parse_args(int argc, char **argv){
	int filenamesize;
	char *filename, *source;
	long lSize;

	if(argc >= 2){
		/* argv[2] here assumed to be the input file.
		 * later on some error checking, mutiple files, etc
		 * will get added.  */
		filenamesize = strlen(argv[1]);
		filename = malloc(filenamesize * sizeof(char));
		strcpy(filename, argv[1]);
		FILE *source_fp;
		source_fp = fopen(filename, "rb");
		if(!source_fp) perror(filename), exit(1);

		fseek(source_fp, 0L, SEEK_END);
		lSize = ftell(source_fp);
		rewind(source_fp);

		source = calloc(1, lSize+1);
		if(!source) fclose(source_fp), fputs("Memory alloc fails",
				stderr), exit(1);
		if(1 != fread(source, lSize, 1, source_fp))
			fclose(source_fp), free(source), fputs("Read fails",
					stderr), exit(1);
		tokenize(source);

		fclose(source_fp);
		free(source);
	}
	else{
		printf("No file to compile provided\n");
	}
}

int main(int argc, char *argv[]){
	parse_args(argc, argv);


	return 0;
}
