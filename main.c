/* The compiler */
#include <stdio.h>

int main(int argc, char *argv[]){
	int c;

	FILE *source_fp;
	source_fp = fopen("test.c", "r");

	if(source_fp){
		while ((c = getc(source_fp)) != EOF){
			putchar(c);
		}
	}
	else{
		printf("Reading file \"test.c\" failed");
	}
	fclose(source_fp);

	return 0;
}
