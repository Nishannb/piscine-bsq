#include "headers/functions.h"

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	while (*str != '\0')
	{
		print_char(*str);
		str++;
	}
}