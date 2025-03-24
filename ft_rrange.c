// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// int	amount(int start, int end)
// {
// 	int	size = 1;
// 	if (end == start)
// 		return (size);
// 	if (end > start)
// 		size += (end - start);
// 	if (start > end)
// 		size += (start - end);
// 	return (size);
// }

// int	*ft_rrange(int start, int end)
// {

// 	int	*numbers;
// 	numbers = malloc(amount(start, end)*sizeof(int));
// 	int	i = 0;
// 	while (end > start)
// 	{
// 		numbers[i] = end;
// 		end--;
// 		i++;
// 	}
// 	while (start > end)
// 	{
// 		numbers[i] = end;
// 		end++;
// 		i++;
// 	}
// 	numbers[i] = start;
// 	return (numbers);
// }

// // int	main(void)
// // {
// // 	int	start = -2;
// // 	int	end = -2;
// // 	int	*numbers = ft_rrange(start, end);
// // 	int	i = 0;
// // 	while (i < amount(start, end))
// // 	{
// // 		printf("numbers[%d] = %d\n", i, numbers[i]);
// // 		i++;
// // 	}
// // 	return (0);
// // }