// #include <unistd.h>
// #include <stdio.h>

// int based_digit(char c)
// {
// 	char	*hex = "0123456789abcdef";
// 	int	i = 0;
// 	int	nb = 0;

// 	while(hex[i])
// 	{
// 		if (c == hex[i])
// 			nb = i;
// 		i++;
// 	}
// }

// int	ft_atoi_base(char *str, unsigned int base)
// {
// 	int i = 0;
// 	int nb = 0;
// 	int sign = 1;

// 	if (str[i] == '-')
// 	{
// 		i++;
// 		sign = -1;
// 	}
// 	if (str[i] < '0' ||
// 	str[i] > '9' && str[i] < 'A' ||
// 	str[i] > 'F' && str[i] < 'a' ||
// 	str[i] > 'f')
// 		return 0;
// 	while(str[i])
// 	{
// 		nb += based_digit(str[i]);
// 		if (str[i + 1] != '\0' )
// 			nb *= base;
// 		i++;
// 	}
// 	return (nb * sign);
// }

// int	main()
// {
// 	ft_atoi_base("--a", 14);
// 	return (0);
// }