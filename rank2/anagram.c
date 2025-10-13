// #include <unistd.h>
// #include <stdio.h>

// int	ft_strlen(char *str)
// {
// 	int	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	main(int argc, char *argv[])
// {
// 	char	*s1 = argv[1];
// 	char	*s2 = argv[2];
// 	int		i = 0;
// 	int		j = 0;
// 	int		count = 0;
// 	int		round = 0;

// 	if (argc != 3)
// 		return (printf("no good amount of arguments"), -1);
// 	while (s2[j])
// 	{
// 		if (round > ft_strlen(s1))
// 		{
// 			printf("strlen: %d\n", ft_strlen(s1));
// 			break ;
// 		}
// 		if (s1[i] == '\0')
// 		{
// 			round++;
// 			i = 0;
// 		}
// 		if ((s2[j] == s1[i]) && s2[j])
// 		{
// 			printf("s2[j]: %c\n", s2[j]);
// 			s1[i] = 127;
// 			j++;
// 			count++;
// 		}
// 		printf("count: %d\n", count);
// 		if (count >= ft_strlen(s1))
// 			return (printf("count is the same as length"), 0);
// 		i++;
// 	}
// 	return (printf("something went wrong"), -1);
// }