/* The number, 197, is called a circular prime because all rotations of the digits: 197, 		*/
/* 971, and 719, are themselves prime. 															*/
/* There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.*/
/* How many circular primes are there below one million? 										*/
/* Solution = 55 																				*/

#include <iostream>
#include <math.h>

using namespace std;

char	is_prime(int in)
{
	int n = in;

	if (in < 0)
		n *= -1;
	if (n == 1) return (0);
	if (n < 4) return (1);
	if (n % 2 == 0) return (0);
	if (n < 9) return (1);
	if (n % 3 == 0) return (0);
	int root = sqrt(n) + 1;
	int f = 5;
	while (f < root)
	{
		if (n % f == 0) return (0);
		if (n % (f + 2) == 0) return (0);
		f += 6;
	}
	return (1);
}

int		circular_primes(int limit)
{
	int		i;
	int		cnt = 1;
	string	num;
	string	str;
	bool	prime;

	for (i = 3; i < limit; i += 2)
	{
		str = to_string(i);
		num = str;
		prime = true;
		do
		{
			if (!is_prime(atoi(num.c_str())))
			{
				prime = false;
				break ;
			}
			rotate(num.begin(), num.begin() + 1, num.end());
		} while(num != str);
		if (prime == true)
			cnt++;
	}
	return (cnt);
}

int		main(void)
{
	int ans = circular_primes(1000000);
	cout << ans << '\n';
	return (0);
}
