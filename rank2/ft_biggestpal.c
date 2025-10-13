// #include <unistd.h>
// #include <stdio.h>

// void bpal(char *str)
// {
// 	char *curr_pal = NULL;
// 	int	curr_len = 0;
// 	int	i = 0;
// 	int	j = 0;

// 	while (str[i])
// 	{
// 		i++;
// 		if (str[i - 1] == str[i + 1]) //odd_pal
// 		{
// 			while (str[i + j] && (str[i - j] == str[i + j]))
// 			{
// 				j++;
// 			}
// 			if (curr_len <= (j + j - 1))
// 			{
// 				curr_pal = str + i - j + 1;
// 				curr_len = j + j - 1;
// 			}
// 			j = 0;
// 		}
// 		if (str[i] == str[i + 1]) //even_pal
// 		{
// 			while (str[i + j + 1] && (str[i - j] == str[i + 1 + j]))
// 			{
// 				j++;
// 			}
// 			if (curr_len <= (j + j))
// 			{
// 				curr_pal = str + i - j + 1;
// 				curr_len = j + j;
// 			}
// 			j = 0;
// 		}
// 	}
// 	if (curr_pal == NULL)
// 	{
// 		curr_pal = &str[i - 1];
// 		curr_len = 1;
// 	}
// 	printf("len = %d\n", curr_len);
// 	write(1, curr_pal, curr_len);
// }

// int	main(int argc, char *argv[])
// {
// 	bpal(argv[1]);
// 	return (0);
// }
