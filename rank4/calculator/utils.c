#include "header.h"

char *expr_dup(char **arg)
{
	char *s;
	int i = 0;

	(*arg)++;
	while((*arg)[i] != ')')
		i++;
	s = malloc(i + 1);
	i = 0;
	while (**arg != ')')
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

void print_data(t_data *data)
{
	while (data)
	{
		printf("expr: %s\n", data->expr);
		printf("num: %d\n", data->num);
		printf("sign: %c\n\n", data->sign);
		data = data->next;
	}
}
