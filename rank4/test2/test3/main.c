#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct data
{
	char *expr;
	int num;
	char sign;
	struct data *next;
}			t_data;

#define NUM -1
#define SIGN -2

int calc(char *arg);

bool validate(char c, int *expecting, int *bracket)
{
	if (*expecting == NUM){
		if (isdigit(c))
			*expecting = SIGN;
		else if (c == '(')
			(*bracket)++;
		else{
			printf("Unexpected token '%c'\n", c);
			return false;
		}
	}
	else if (*expecting == SIGN){
		if (c == '+' || c == '*')
			*expecting = NUM;
		else if (c == ')')
			(*bracket)--;
		else{
			printf("unexected token '%c'\n", c);
			return false;
		}
	}
	if (*bracket < 0){
		printf("Unexpected token '%c'\n", c);
		return false;
	}
	return true;
}

bool is_valid(char *arg)
{
	int expecting = NUM;
	int bracket = 0;

	while (*arg){
		if (validate(*arg, &expecting, &bracket) == false)
			return false;
		arg++;
	}
	if (expecting == NUM || bracket != 0){
		printf("Unexpected end of input\n");
		return false;
	}
	return true;
}

int to_digit(char c)
{
	int n;

	n = c - '0';
	return n;
}

char *expr_dup(char **arg)
{
	char *s;
	int len = 0;
	int i = 0;
	int bracket = 1;

	(*arg)++;
	while ((*arg)[len]){
		if ((*arg)[len] == '(')
				bracket++;
		else if ((*arg)[len] == ')')
			bracket--;
		if (bracket == 0)
			break ;
		len++;
	}
	s = malloc(len + 1);
	while (len > i){
		s[i] = **arg;
		i++;
		(*arg)++;
	}
	s[i] = '\0';
	return s;
}

t_data *new_node(char **arg)
{
	t_data *new = malloc(sizeof(t_data));

	if (**arg == '('){
		new->expr = expr_dup(arg);
		new->num = -1;
	}
	else if (isdigit(**arg)){
		new->expr = NULL;
		new->num = to_digit(**arg);
	}
	(*arg)++;
	if (**arg)
		new->sign = **arg;
	else
		new->sign = '\0';
	new->next = NULL;
	return new;
}

void add_node_back(t_data **data, t_data *new)
{
	t_data *temp;

	if (*data == NULL){
		*data = new;
		return ;
	}
	temp = *data;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void parse(t_data **data, char *arg)
{
	t_data *new;

	while (*arg){
		new = new_node(&arg);
		add_node_back(data, new);
		if (!*arg)
			break ;
		arg++;
	}
}

void solve_expr(t_data *data)
{
	while (data){
		if (data->expr){
			data->num = calc(data->expr);
			free(data->expr);
			data->expr = NULL;
		}
		data = data->next;
	}
}

void solve_mult(t_data *data)
{
	t_data *temp;

	while (data){
		while (data->sign == '*'){
			temp = data->next;
			data->num *= temp->num;
			data->sign = temp->sign;
			data->next = temp->next;
			free(temp);
		}
		data = data->next;
	}
}

void solve_add(t_data *data)
{
	t_data *temp;

	while (data->next){
		temp = data->next;
		data->num += temp->num;
		data->next = temp->next;
		free(temp);
	}
}

int calc(char *arg)
{
	t_data *data = NULL;
	int result;

	parse(&data, arg);

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
		return 1;
	if (is_valid(argv[1]) == false)
		return 1;
	result = calc(argv[1]);
	printf("%d\n", result);
	return 0;
}