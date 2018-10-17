/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. */
/* Find the sum of all the primes below two million. */
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

long		sum_prime_below_limit(int limit)
{
	long	val = 3;
	long	sum = 2;

	while (val < limit)
	{
		if (is_prime(val))
			sum += val;
		val += 2;
	}
	return (sum);

}

int		main(void)
{
	long ans = sum_prime_below_limit(2000000);
	printf("%ld\n", ans);
	return (0);
}
