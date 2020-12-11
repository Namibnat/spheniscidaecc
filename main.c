/* The compiler */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int c;
	int filenamesize;
	char *filename;

	if(argc >= 2){
		filenamesize = strlen(argv[1]);
		filename = malloc(filenamesize * sizeof(char));
		strcpy(filename, argv[1]);
		FILE *source_fp;
		source_fp = fopen(filename, "r");

		if(source_fp){
			while ((c = getc(source_fp)) != EOF){
				putchar(c);
			}
			fclose(source_fp);
		}
		else{
			printf("Reading file \"test.c\" failed\n");
		}
	}
	else{
		printf("No file to compile provided\n");
	}



	return 0;
}
