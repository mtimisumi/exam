// #include <unistd.h>
// #include <stdio.h>


// int ft_strlen(char *str)
// {
// 	int i = 0;
// 	while (str && str[i])
// 		i++;
// 	return (i);
// }

// //still wrong... try ./a.out ffloor lofrfq
// int anagr(char *s1, char *s2)
// {
// 	int i = 0;
// 	int j = -1;
// 	int found = 0;
// 	// int letters = ft_strlen(s1);

// 	if (ft_strlen(s1) != ft_strlen(s2))
// 		return -2;

// 	while (s1[i])
// 	{
// 		while (s2[j++] && !found)
// 		{
// 			if (s1[i] == s2[j])
// 			{
// 				s2[j] = -1;
// 				i++;
// 				found = 1;
// 			}
// 		}
// 		if (!s2[j])
// 			return -1;
// 		j = -1;
// 		i++;
// 		found = 0;
// 	}
// 	return 0;
// }






// // silent .. listen
// int main(int argc, char *argv[])
// {
// 	if (argc != 3)
// 		printf("need 2 args");
// 	else if (anagr(argv[1], argv[2]) == -2)
// 		printf("not same lengh");
// 	else if (!anagr(argv[1], argv[2]))
// 		printf("anagram");
// 	else
// 		printf("NOT!!!");
// }