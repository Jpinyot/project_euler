/* Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide 	*/
/* evenly into n). 																				*/
/* If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of 		*/
/* a and b are called amicable numbers. 														*/
/* For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; 		*/
/* therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220. */
/* Evaluate the sum of all the amicable numbers under 10000. 									*/
/* Solution = 31626 																			*/

#include <iostream>
#include <math.h>

int		sum_proper_divisors(int limit)
{
	int		i;
	int		sum = 1;
	int		root = sqrt(limit) + 1;

	for(i = 2; i < root;i++)
		if (limit % i == 0 && i * i != limit)
			sum += i + limit / i;
	return (sum);
}

int		proper_divisors_finder(int limit)
{
	int		sum = 0;
	int		val;
	int		i;

	for (i = 2; i < limit; i++)
		if ((val = sum_proper_divisors(i)) != i && sum_proper_divisors(val) == i)
			sum += val;
	return (sum);
}

int 	main(void)
{
	int ans = proper_divisors_finder(10000);
	std::cout << ans << '\n';
	return (0);
}
