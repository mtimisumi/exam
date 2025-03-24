#include <unistd.h>
#include <stdio.h>


int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_union(char *str1, char *str2)
{
	int	len = ft_strlen(str1) + ft_strlen(str2);
	char	str[len];
	int	j = 0;
	int	count = 0;
	int	index = 0;
	int	yo = 0;
	char	written[len];

	while (str1[yo])
	{
		str[yo] = str1[yo];
		yo++;
	}
	while (*str2)
	{
		str[yo] = *str2;
		yo++;
		str2++;
	}
	str[yo] = '\0';
	yo = 0;
	while(str[yo])
	{
		while (written[j])
		{
			if (str[yo] == written[j])
				count = 1;
			j++;
		}
		j = 0;
		if (count == 0)
		{
			written[index] = str[yo];
			yo++;
			index++;
		}
		if (count == 1)
		{
			yo++;
			count = 0;
		}
	}
	j = 0;
	write (1, &written, index);
}

int	main(int argc, char *argv[])
{
	printf("argc: %d\n", argc);
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	else
		printf("no good arguments");
	return (0);
}
