/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26. 							*/
/* What is the sum of the digits of the number 2^1000? 											*/
/* Solution = 1366 																				*/

#include <stdio.h>
#include <math.h>
#include <iostream>


long	sum_of_pow(int n, int n_pow)
{
	long	sum = 0;

	std::string str = std::to_string(pow(n, n_pow));
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
	{
		if (*it < '0' || *it > '9')
			break;
		sum += *it - '0';
	}
	return (sum);
}

int		main(void)
{
	long	ans = sum_of_pow(2, 1000);
	printf("%li\n", ans);
	return (0);
}
