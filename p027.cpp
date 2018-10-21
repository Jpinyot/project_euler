/* Find the product of the coefficients, a and b, for the quadratic expression that produces 	*/
/* the maximum number of primes for consecutive values of n, starting with n=0. 				*/
/* n^2+a*n+b, where |a|<1000 and |b|≤1000 														*/
/* Solution = -59231 																			*/

#include <iostream>
#include <math.h>
#include <unistd.h>

using namespace std;

char	is_prime(long in)
{
	long n = in;

	if (in < 0)
		n *= -1;
	if (n == 1) return (0);
	if (n < 4) return (1);
	if (n % 2 == 0) return (0);
	if (n < 9) return (1);
	if (n % 3 == 0) return (0);
	int root = sqrt(n);
	int f = 5;
	while (f < root)
	{
		if (n % f == 0) return (0);
		if (n % (f + 2) == 0) return (0);
		f += 6;
	}
	return (1);
}
int		product_consecutive_primes(int limit)
{
	int		a;
	int		b;
	long	n;
	int		cnt;
	int		mult_ret;
	int		cmp_cnt = 0;

	for (a  = -limit + 1; a < limit; a++)
	{
		for (b = -limit + 1; b < limit; b++)
		{
			for (cnt = 0; ; cnt++)
			{
				n = (pow(cnt, 2) + (a * cnt) + b);
				if (!is_prime(n))
					break ;
			}
			if (cnt > cmp_cnt)
			{
				cmp_cnt = cnt;
				mult_ret = a * b;
			}
		}
	}
	return (mult_ret);
}

int		main(void)
{
	int ans =  product_consecutive_primes(1000);
	cout << ans << '\n';
	return (0);
}
