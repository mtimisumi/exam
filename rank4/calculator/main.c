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
	data = NULL;
	return result;
}

int main(int argc, char *argv[])
{
	t_data *data = NULL;
	int result;

	if (argc != 2)
		return 0;
	
	if (is_valid(argv[1]) == false)
		return 1;
	// parse(argv[1], &data);
	// print_data(data);
	// result = solve(&data);
	result = calc(argv[1]);
	printf("final result: %d\n", result);
	return 0;
}