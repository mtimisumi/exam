#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

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
			printf("Unexpected token '%c'\n", argv[i]);
			return 1;
		}
		i++;
	}
	if (a != 0){
		printf("Unexpected end of input\n");
		return 1;
	}
	return 0;
}

int expecting_num(char c)
{
	if (c == '\0'){
		return 0;
	}
	if (isdigit(c) || c == '('){
		return 1;
	}
	return 0;
}

int expecting_sign(char c)
{
	if (c == '\0'){
		return 0;
	}
	if (c == '+' || c == '*' || c == ')'){
		return 1;
	}
	return 0;
}


int order(char *argv)
{
	int expecting = NUM;
	int i = 0;
	
	if (!argv[1] && !isdigit(argv[0])){
		return 1;
	}
	while (argv[i])
	{
		if (expecting == NUM){
			if (!expecting_num(argv[i])){
				printf("Unexpected end of input\n");
				return 1;
			}
			if (argv[i] != '('){
				expecting = SIGN;
			}
		}
		else if (expecting == SIGN){
			if (!expecting_sign(argv[i])){
				printf("Unexpected end of input\n");
				return 1;
			}
			if (argv[i] != ')'){
				expecting = NUM;
			}
		}
		if (!argv[i + 1] && (argv[i]) == '+' || argv[i] == '*'){
			printf("Unexpected end of input\n");
			return 1;
		}
		i++;
	}
	return 0;
}

int parse(char *argv)
{
	if (unexpected_token(argv) == 1){
		return 1;
	}
	if	(parenthesis(argv) == 1){
		return 1;
	}
	if (order(argv) == 1){
		return 1;
	}
	printf("zero errors\n");
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
