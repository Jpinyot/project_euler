/* The prime factors of 13195 are 5, 7, 13 and 29. 												*/
/* What is the largest prime factor of the number 600851475143 ? 								*/
/* Solution = 6857(Fermat Method)																*/

#include <stdio.h>
#include <stdlib.h>
int TEST_MAX = 10;

int		power(int a, int n, int p)
{
	int res = 1;
	a %= p;

	while (n > 0)
	{
		if (n & 1)
			res = (res*a) % p;
		n = n>>1;
		a = (a*a) % p; 
	}
	return (res);
}

int		is_prime(long n, int k)
{
	int i = -1;
	int test;

	if (n <= 1 || n == 4)  return (0);
	if (n <= 3) return (1);
	while(++i < k)
	{
		test = 2 + rand() % (n - 4);
		if (power(test, n-1, n) != 1) 
          return (0);
	}
	return (1);
}

int		largest_prime_factor(long value)
{
	long	i = 1;
	long	max_factor = 0;
	int		prime;

	if (value  <= 0 || value == 4)
		return (0);
	while (i < value / i)
	{
		if (value % i == 0)
			if ((prime = is_prime(i, TEST_MAX)))
				max_factor = i;
		i++;
	}
	return (max_factor);

}

int		main(void)
{
	long ans = largest_prime_factor(600851475143);
	printf("%ld\n", ans);
	return (0);
}
