#include "header.h"

// i only need to add the double pointer if i were to free, so i can change it if i need in future
void solve_expr(t_data *data)
{
	int result;

	while (data)
	{
		t_data *expr = NULL;
		if (data->expr){
			printf("entering expression\n");
			parse(data->expr, &expr);
			result = solve(&expr);
			free(data->expr);
			data->expr = NULL;
			data->num = result;
		}
		data = (data)->next;
	}
}

void solve_mult(t_data *data)
{
	t_data *temp;

	while (data && data->next)
	{
		while (data->sign == '*'){
			data->num *= (data->next)->num;
			printf("n after mult: %d\n", data->num);
			data->sign = (data->next)->sign;
			temp = data->next;
			data->next = (data->next)->next;
			free(temp);
		}
		data = data->next;
	}
}

void solve_add(t_data *data)
{
	t_data *temp;

	while (data && data->next)
	{
		data->num += (data->next)->num;
		printf("n after add: %d\n", data->num);
		temp = data->next;
		data->next = (data->next)->next;
		free(temp);
	}
}

int solve(t_data **data)
{
	int result;

	print_data(*data);
	solve_expr(*data);
	solve_mult(*data);
	solve_add(*data);
	result = (*data)->num;
	free(*data);
	*data = NULL;
	printf("result: %d\n", result);
	return result;
}
