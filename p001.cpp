/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9*/
/* The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.     */
/* Solution =	233168																			 */

#include <stdio.h>

int		sum_multiples_below_x(int n1, int n2, int x)
{
	int i = -1;
	int	ans = 0;

	while (++i < x)
		if (i % n1 == 0 || i % n2 == 0)
			ans += i;
	return (ans);
}

int		main(void)
{
	int	ans = sum_multiples_below_x(3, 5, 1000);
	printf("%i", ans);
	return (0);
}
