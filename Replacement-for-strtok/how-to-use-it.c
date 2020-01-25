#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_next_token.h"

/**
 * a test function 
 */
void test(const char *string, char *delimiters) {
  printf(
      "Test with\n"
      "- string     = \"%s\"\n"
      "- delimiters = \"%s\"\n",
      string, delimiters);
  
  const char *where = string;
  while (true) {
	  const char *start = get_next_token(&where, " :,");
	  if (start == NULL) break;
	  
	  // token starts at start,
	  // *where has moved to char after the token
	  
	  char *token = strndup(start, where - start);
	  printf("-> \"%s\"\n", token);
	  free(token);
  }
  printf("\n");
}

/**
 * perform tests
 */

int main() {
	test("  first   test  ", " ");
	test(" another:test with   ::: several ,, delimiters", " :");
	return 0;
}


