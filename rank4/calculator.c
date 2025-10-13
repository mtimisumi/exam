#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM -1
#define SIGN -2

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


int main(int argc, char *argv[])
{
	if (argc != 2)
		return 0;
	
	if (is_valid(argv[1]) == false)
		return 1;
	printf("+\n");
	return 0;
}
