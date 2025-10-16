#include "header.h"

// int calc()
// {
// 	t_data *data = NULL

// }

int main(int argc, char *argv[])
{
	t_data *data = NULL;
	int result;

	if (argc != 2)
		return 0;
	
	if (is_valid(argv[1]) == false)
		return 1;
	parse(argv[1], &data);
	print_data(data);
	result = solve(&data);
	printf("final result: %d\n", result);
	return 0;
}