/* The sum of the squares of the first ten natural numbers is, 12 + 22 + ... + 102 = 385. 		*/
/* The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)2 = 552 = 3025. */
/* Hence the difference between the sum of the squares of the first ten natural numbers and the */
/* square of the sum is 3025 − 385 = 2640. 														*/
/* Find the difference between the sum of the squares of the first one hundred natural numbers	*/
/* and the square of the sum. 																	*/
/* Solution = */

#include <stdio.h>
#include <math.h>

int		difference_sum_square(int limit)
{
	int sqr_sum = pow((limit * (limit + 1)) / 2, 2);
	int sum_sqr = limit * (limit + 1) * (2 * limit + 1) / 6;
	return (sqr_sum - sum_sqr);
}

int		main(void)
{
	int	ans = difference_sum_square(100);
	printf("%i", ans);
	return (0);
}
