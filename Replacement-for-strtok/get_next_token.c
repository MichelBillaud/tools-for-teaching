#include <stdbool.h>
#include <string.h>

#include "get_next_token.h"

const char *get_next_token(const char **where, const char *delimiters) {
  while (**where != '\0' && strchr(delimiters, **where) != NULL) {
    (*where)++;
  }
  if (**where == '\0') {
    return NULL;
  }
  const char *start = *where;
  while (**where != '\0' && strchr(delimiters, **where) == NULL) {
    (*where)++;
  }
  return start;
}
