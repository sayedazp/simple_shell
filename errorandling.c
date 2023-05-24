#include "main.h"

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _eputchar(char c)
{
	static int i;
	static char buf[WB_SIZE];

	if (c == B_FLUSH || i >= WB_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}

	if (c != B_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input)
{

	int i, count = 0;
	unsigned int _abs_, current;

	if (input < 0)
	{
		_abs_ = -input;
		_eputchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			_eputchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	_eputchar('0' + current);
	count++;

	return (count);
}