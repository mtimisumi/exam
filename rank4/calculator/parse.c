#include "header.h"

void add_node_back(t_data **data, t_data *new)
{
	t_data *temp;

	temp = *data;
	if (*data == NULL){
		*data = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_data *new_node(char **arg)
{
	t_data *new = malloc(sizeof(t_data));

	if (**arg == '('){
		char *s = expr_dup(arg);
		new->expr = s;
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
	return (new);
}

void parse(char *arg, t_data **data)
{
	t_data *new;

	while (*arg)
	{
		new = new_node(&arg);
		add_node_back(data, new);
		if (!*arg)
			break ;
		arg++;
	}
}
