#include "header.h"

int calc(char *arg)
{
	t_data *data = NULL;
	int result;

	parse(arg, &data);
	solve_expr(data);
	solve_mult(data);
	solve_add(data);
	result = data->num;
	free(data);
	return result;
}

int main(int argc, char *argv[])
{
	int result;

	if (argc != 2)
		return 0;
	if (is_valid(argv[1]) == false)
		return 1;
	result = calc(argv[1]);
	printf("%d\n", result);
	return 0;
}