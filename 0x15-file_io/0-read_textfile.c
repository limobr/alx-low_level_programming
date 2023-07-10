#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Filename to be read
 * @letters: Number of letters to be read and print
 *
 * Return: The actual number of letters read and printed,
 * or 0 if an error occurred
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int sv;
	ssize_t bytes_read, bytes_written;
	char *buff;

	if (filename == NULL)
		return (0);

	sv = open(filename, O_RDONLY);
	if (sv == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	bytes_read = read(sv, buff, letters);
	if (bytes_read == -1)
	{
		free(buff);
		close(sv);
		return (0);
	}

	bytes_written = write(STDOUT_FILENO, buff, bytes_read);
	if (bytes_written == -1 || bytes_written != bytes_read)
	{
		free(buff);
		close(sv);
		return (0);
	}

	free(buff);
	close(sv);
	return (bytes_written);
}
