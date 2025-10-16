#include "header.h"

char *expr_dup(char **arg)
{
	char *s;
	int len = 0;
	int i = 0;
	int bracket = 1;

	(*arg)++;
	while ((*arg)[len])
	{
		if ((*arg)[len] == '(')
			bracket++;
		if ((*arg)[len] == ')'){
			bracket--;
			if (bracket == 0)
				break;
		}
		len++;
	}
	s = malloc(len + 1);
	while (len > i)
	{
		s[i] = **arg;
		i++;
		(*arg)++;
	}
	s[i] = '\0';
	return s;
}

int to_digit(char c)
{
	int n;

	n = c - '0';
	return n;
}
