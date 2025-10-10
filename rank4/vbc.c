#include <unistd.h>
#include <stdio.h>

#define NUM -1
#define SIGN -2

int unexpected_token(char *argv)
{
	int i = 0;

	while (argv[i])
	{
		if (!isdigit(argv[i]) && argv[i] != '(' && argv[i] != ')'
			&& argv[i] != '+' && argv[i] != '*'){
				printf("Unexpected token '%c'\n", argv[i]);
				return 1;
			}
		i++;
	}
	return 0;
}

int parenthesis(char *argv)
{
	int a = 0;
	int i = 0;

	while (argv[i])
	{
		if (argv[i] == '('){
			a++;
		}
		if (argv[i] == ')'){
			a--;
		}
		if (a < 0){
			printf("Unexpected end of input\n");
			return 1;
		}
	}
	if (a != 0){
		return 1;
	}
	return 0;
}

int order(char *argv)
{
	int expecting;
	int i = 1;

	if (!isdigit(argv[0]) || argv[i] != '('){
		return 1;
	}
	while(argv[i])
	{
		if (argv[i] == '(' || argv[i] == ')'){
			expecting = NUM;
		}
		if (isdigit(argv[i])){
			if (expecting != NUM){
				return 1;
			}
			expecting = SIGN;
		}
		if (argv[i] == '+' || argv[i] == '*'){
			if (expecting != SIGN){
				return 1;
			}

		}

	}

}

int parse(char *argv)
{
	if (unexpected_tokens(argv) == 1){
		return 1;
	}
	if	(parenthesis(argv) == 1){
		return 1;
	}
	if (operation(argv) == 1){
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2){
		return 0;
	}
	if (parse(argv[1]) == 1){
		return 1;
	}
	return 0;
}
