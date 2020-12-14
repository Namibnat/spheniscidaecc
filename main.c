/* The compiler */

#include "spheniscidaecc.h"
	
char *source;

static int parse_args(int argc, char **argv){
	int filenamesize, parsed;
	char *filename;
	long lSize;

	if(argc >= 2){
		/* argv[2] here assumed to be the input file.
		 * later on some error checking, mutiple files, etc
		 * will get added. 
		 *
		 * I'm copying the filename because I know in the end I'll
		 * need to copy a few of them.
		 */
		filenamesize = strlen(argv[1]);
		filename = malloc(filenamesize * sizeof(char));
		strcpy(filename, argv[1]);

		FILE *source_fp;
		source_fp = fopen(filename, "rb");
		if(!source_fp) perror(filename), exit(1);
		free(filename);

		fseek(source_fp, 0L, SEEK_END);
		lSize = ftell(source_fp);
		rewind(source_fp);

		source = calloc(1, lSize+1);
		if(!source){
		       	fclose(source_fp);
			fputs("Memory allocation failed", stderr);
		       	exit(1);
		}
		if(1 != fread(source, lSize, 1, source_fp)){
			fclose(source_fp);
			free(source);
			fputs("Read fails", stderr);
			exit(1);
		}
		fclose(source_fp);
		parsed = 1;
	}
	else{
		printf("No file to compile provided\n");
		parsed = 0;
	}
	return parsed;
}

int main(int argc, char *argv[]){
	if(parse_args(argc, argv)){
		tokenize(source);
	}

	return 0;
}
