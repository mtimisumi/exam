#include "header.h"

void solve_expr(t_data *data)
{
	int result;

	while (data)
	{
		if (data->expr){
			result = calc(data->expr);
			free(data->expr);
			data->expr = NULL;
			data->num = result;
		}
		data = data->next;
	}
}

void solve_mult(t_data *data)
{
	t_data *temp;

	while (data && data->next)
	{
		while (data->sign == '*'){
			data->num *= (data->next)->num;
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

	while (data->next)
	{
		data->num += (data->next)->num;
		temp = data->next;
		data->next = (data->next)->next;
		free(temp);
	}
}
