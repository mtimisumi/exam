// #include <stdio.h>
// #include <unistd.h>
// #include <limits.h>





// //       ./a.out 23 422 121 7


// int ft_atoi(char *nb)
// {
// 	int res = 0;
// 	int sign = 1;
	
// 	if (*nb == '-')
// 	{
// 		nb++;
// 		sign = -1;
// 	}
// 	while (*nb)
// 	{
// 		res += *nb - '0';
// 		if (*(nb + 1) != '\0')
// 			res *= 10;
// 		nb++;
// 	}
// 	return (res * sign);
// }

// void wriite(int nb)
// {
// 	char c;

// 	if (nb == INT_MIN)
// 	{
// 		write(1, "-2147483648", 11);
// 		return ;
// 	}
// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb >= 10)
// 		wriite(nb / 10);
// 	c = nb % 10 + '0';
// 	write(1, &c, 1);
// }

// void psum(int amount, char **argv)
// {
// 	int i = 1;
// 	int sum = 0;

// 	while (i <= amount)
// 	{
// 		sum += ft_atoi(argv[i]);
// 		i++;
// 	}

// 	wriite(sum);
// }

// int main(int argc, char *argv[])
// {
// 	if (argc > 1)
// 		psum(argc - 1, argv);
// 	write(1, "\n", 1);
// }