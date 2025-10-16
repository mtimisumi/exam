
#ifndef HEADER_H
#define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdlib.h>

# define NUM -1
# define SIGN -2

typedef struct data
{
	char *expr;
	int num;
	char sign;
	struct data *next;
}			t_data;

int main(int argc, char *argv[]);
bool is_valid(char *arg);
void parse(char *arg, t_data **data);
int solve(t_data **data);

// temp
void print_data(t_data *data);

// utils
int to_digit(char c);
char *expr_dup(char **arg);

#endif
