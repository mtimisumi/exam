#include <unistd.h>
#include <stdio.h>


// int to_int(char *str)
// {
// 	int	nb = 0;
// 	int	i = 0;

// 	while (str[i])
// 	{
// 		if (str[i + 1] != '\0')
// 		{
// 			nb = (nb + (str[i] - '0')) * 10;
// 		}
// 		else if (str[i + 1] == '\0')
// 			nb = nb + (str[i] - '0');
// 		i++;
// 	}
// 	return nb;
// }




// void	print_hex(int nb)
// {
// 	char *str = "0123456789abcdef";
// 	if ((nb / 16) > 15)
// 		print_hex(nb / 16);
// 	else
// 		write(1, &str[nb / 16], 1);
// 	write(1, &str[nb % 16], 1);
	
// }

// int	main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		int nb = to_int(argv[1]);
// 		print_hex(nb);
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }



















































int	to_int(char *str)
{
	int	nb = 0;
	while (str[nb])
	{
		nb = nb + (nb - '0');
		if (str[nb + 1] != '\0')
			nb = nb * 10;
	}
	reutrn (nb);
}





void	print_hex(char *str)
{

}






int	main(int argc, char *argv[])
{
	if (argc == 2)
		print_hex(argv[1]);
	write(1, "\n", 1);
	return (0);
}

















