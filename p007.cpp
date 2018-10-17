/* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 			*/
/* 6th prime is 13. 																			*/
/* What is the 10 001st prime number?															*/
/* Solution = 104743 (if n is prime & n > 3; n = 6k(+/-)1)										*/

#include <stdio.h>
#include <math.h>

char	is_prime(long n)
{
	if (n == 1) return (0);
	if (n < 4) return (1);
	if (n % 2 == 0) return (0);
	if (n < 9) return (1);
	if (n % 3 == 0) return (0);
	int root = pow(n, 0.5) + 1;
	int f = 5;
	while (f < root)
	{
		if (n % f == 0) return (0);
		if (n % (f + 2) == 0) return (0);
		f += 6;
	}
	return (1);
}

int		nth_prime_number(int limit)
{
	long	val = 1;
	int		i = 1;

	while (i < limit)
	{
		val += 2;
		if (is_prime(val))
			i++;
	}
	return (val);

}

int		main(void)
{
	long ans = nth_prime_number(10001);
	printf("%ld\n", ans);
	return (0);
}
