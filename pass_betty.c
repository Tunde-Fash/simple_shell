#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _strlen - Calculate the length of a string
 * @s: The input string
 * Return: The length of the string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	len++;

	return (len);
}

/**
 * _puts - Print a string to stdout
 * @str: The input string
 */
void _puts(const char *str)
{
	write(1, str, _strlen(str));
	write(1, "\n", 1);
}

/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void)
{
	_puts("Hello, Betty!");
	return (0);
}
