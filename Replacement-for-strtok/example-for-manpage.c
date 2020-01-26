#include <stdio.h>
#include <stdlib.h>

#include "get_next_token.h"

int main(int argc, char *argv[])
{	
	if (argc != 3) {
		fprintf(stderr, "Usage: %s string delimiters\n",
				argv[0]);
		exit(EXIT_FAILURE);
	}

	const char *start = argv[1];
	const char *delimiters = argv[2];
	for (int i = 1;; i++) { 
		const char *token = get_next_token(& start, delimiters);
		if (token == NULL) {
			break;
		}
		printf("%d : %.*s\n", i, (int) (start-token), token);
	}
	
	return EXIT_SUCCESS;
}
