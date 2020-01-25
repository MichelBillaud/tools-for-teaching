#ifndef GET_NEXT_TOKEN_H
#define  GET_NEXT_TOKEN_H

/**
 * Get a token from a string.
 *
 * A start position pointer is given. The function returns the address of the first
 * character of the token, and moves the start pointer to the char following the token.
 * Token starts at first non-delimiter char, and stops at delimiter or end of string.
 * 
 * \param start        address of a pointer to the buffer.
 * \param delimiters   string of delimiters
 * \return             address of the first char of the token. NULL if not found.
 */

const char *get_next_token(const char **start, const char *delimiters);

#endif

