# A replacement for the infamous strtok function.

-  Michel Billaud, 2020
- <michel.billaud@laposte.net> 

# Why?

I got sick and tired with the `strtok` function,
as a way to scan a string, token by token.

Reasons are in the man page:

~~~
BUGS
    Be cautious when using these functions.  If you do use them, note that:

    * These functions modify their first argument.
    * These functions cannot be used on constant strings.
    * The identity of the delimiting byte is lost.
    * The strtok() function uses a static buffer while parsing, so it's not
      thread safe.  Use strtok_r() if this matters to you.
~~~


# A better way

Here we give the code of a `get_next_token()` function which moves
a pointer along the string to be explored, and returns the address of
next token.  

Benefits

- easy to use
- doesn't modify the string
- thread safe.


As the pointer is moved to the first char after the token,
it is easy to

- handle the token
- proceed with the next one.

 
~~~C
const char *where = string;
while (true) {
	// locate a token
	const char *start = get_next_token(&where, " :,");
	if (start == NULL) break;
		
	// get a copy, and display it
	char *token = strndup(start, where - start); 
	printf("-> \"%s\"\n", token);
	free(token);
}
~~~


# Files

## The `get_next_token` function

- [get_next_token.c](get_next_token.c)
- [get_next_token.h](get_next_token.h)
- [get_next_token.3](get_next_token.3)  -- man page

## Tests

- [how-to-use-it.c](how-to-use-it.c) -- tests
- [Makefile](Makefile)

## Running the test

Displays:

~~~
Test with
- string     = "  first   test  "
- delimiters = " "
-> "first"
-> "test"

Test with
- string     = " another:test with   ::: several ,, delimiters"
- delimiters = " :"
-> "another"
-> "test"
-> "with"
-> "several"
-> "delimiters"
~~~
