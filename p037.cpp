/* The number 3797 has an interesting property. Being prime itself, it is possible to 			*/
/* continuously remove digits from left to right, and remain prime at each stage: 3797, 		*/
/* 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3. 				*/
/* Find the sum of the only eleven primes that are both truncatable from left to right and 		*/
/* right to left. 																				*/
/* NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes. 							*/
/* Soution = 748317 																			*/

#include <iostream>
#include <math.h>
#include <unistd.h>

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

int		truncable_prime(int limit)
{
	int		i;
	int		cnt = 0;
	int		ret = 0;
	string	str;
	string	num;
	bool	prime;

	for (i = 22; cnt < limit; i++)
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
		num.erase(num.begin());
		} while (num.size());
		if (prime)
		{
			num = str;
			num.erase(num.size() - 1);
			do
			{
				if (!is_prime(atoi(num.c_str())))
				{
					prime = false;
					break ;
				}
			num.erase(num.size() - 1);
			} while (num.size());
			if (prime)
			{
				cnt ++;
				ret += i;
			}

		}
	}
	return (ret);
}

int		main(void)
{
	int ans =  truncable_prime(11);
	cout << ans << '\n';
	return (0);
}
