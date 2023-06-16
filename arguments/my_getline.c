#include <stdio.h>
/**
 * ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 * getline()  reads  an  entire  line from stream, storing the address of the buffer containing the text into *lineptr.
       The buffer is null-terminated and includes the newline character, if one was found.
       If *lineptr is set to NULL and *n is set 0 before the call, then getline() will allocate a buffer  for  storing  the
       line.  This buffer should be freed by the user program even if getline() failed.

       Alternatively,  before calling getline(), *lineptr can contain a pointer to a malloc(3)-allocated buffer *n bytes in
       size.  If the buffer is not large enough to hold the line, getline() resizes it with realloc(3),  updating  *lineptr
       and *n as necessary.

       In  either  case,  on a successful call, *lineptr and *n will be updated to reflect the buffer address and allocated
       size respectively.

Return: On success, getline() and getdelim() return the number of characters read, including the  delimiter  character,  but
       not  including  the  terminating null byte ('\0').  This value can be used to handle embedded null bytes in the line
       read.

       Both functions return -1 on failure to read a line (including end-of-file condition).  In the event of an error, er‐
       rno is set to indicate the cause.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	*lineptr = &stream;

	while (stream != NULL)
	{
		if (*stream != EOF)
		{
			write(STDOUT_FILENO, stream, sizeof(stream));
		}
	}
}
