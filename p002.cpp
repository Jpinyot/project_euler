/* Each new term in the Fibonacci sequence is generated by adding the previous two terms. 		*/
/* By starting with 1 and 2, the first 10 terms will be: 										*/
/* 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... 														*/
/* By considering the terms in the Fibonacci sequence whose values do not exceed four 			*/
/* million, find the sum of the even-valued terms. 												*/
/* Solution = 4613732																			*/

#include <stdio.h>

int		sum_fibonacci_even_values(int max_value)
{
	int f1 = 1;
	int	f2 = 1;
	int	ans = 0;
	int	tmp;

	while (f2 < max_value)
	{
		tmp = f2;
		if (f2 % 2 == 0)
			ans += f2;
		f2 += f1;
		f1 = tmp;
	}
	return (ans);

}

int		main(void)
{
	int	ans = sum_fibonacci_even_values(4000000);
	printf("%i", ans);
	return (0);
}
