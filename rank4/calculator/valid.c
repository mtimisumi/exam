#include "header.h"


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
			printf("Unexpected token '%c'\n", c);
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
	int i = 0;
	int expecting = NUM;
	int bracket = 0;

	while (arg[i])
	{
		if (expecting == NUM){
			if (validate(arg[i], &expecting, &bracket) == false)
				return false;
		}
		else if (expecting == SIGN){
			if (validate(arg[i], &expecting, &bracket) == false)
				return false;
		}
		if (!arg[i + 1] && (arg[i] == '+' || arg[i] == '*')){
			printf("Unexpected end of input\n");
			return false;
		}
		i++;
	}
	if (bracket != 0){
		printf("Unexpected end of input\n");
		return false;
	}
	return true;
}
