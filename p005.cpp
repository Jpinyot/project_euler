/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without	*/
/* any remainder. What is the smallest positive number that is evenly divisible by all of the	*/
/* numbers from 1 to 20?																		*/
/* Solution = 232792560																			*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int		smallest_divisible(int k)
{
	int		a[k];
	int		p[k];
	int		i = 1;
	int		j = -1;
	int		limit = sqrt(k);
	char	check = 1;
	int		num = 1;

	while (++i < k)
	{
		if (is_prime(i, 10))
		{
			j++;
			p[j] = i;
		}
	}
	printf("%i\n", limit);
	while (++j < k)
		p[j] = 0;
	for(i = 0; p[i] != 0; i++)
	{
		a[i] = 1;
		if (check)
		{
			if (p[i] <= limit)
				a[i] = (floor(log(k) / log(p[i])));
			else
				check = 0;
		}
		num *= pow(p[i], a[i]);
	}
	return (num);
}

int		main(void)
{
	int ans = smallest_divisible(20);
	printf("%i\n", ans);
	return (0);
}
