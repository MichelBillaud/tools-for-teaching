#include <stdbool.h>
#include <string.h>

#include "get_next_token.h"

const char *get_next_token(const char **where, const char *delimiters) {
	// ignore leading delimiters
	while (**where != '\0'
		   && strchr(delimiters, **where) != NULL) {
		(*where)++;
	}
	// end of string?
	if (**where == '\0') {
		return NULL;
	}
	// token starts here, move to end.
	const char *start = *where;
	while (**where != '\0'
		   && strchr(delimiters, **where) == NULL) {
		(*where)++;
	}
	// job done.
	return start;
}
