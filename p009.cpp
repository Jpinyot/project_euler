/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, 				*/
/* a2 + b2 = c2 																				*/
/* For example, 32 + 42 = 9 + 16 = 25 = 52. 													*/
/* There exists exactly one Pythagorean triplet for which a + b + c = 1000. 					*/
/* Find the product abc. 																		*/
/* Solution = 31875000																			*/

#include <stdio.h>
#include <math.h>

int		pythagorean_product(int n)
{
	int	c;

	for (int a = 1; a <= n; a++)
	{
		for (int b = a + 1; b <= n - a; b++)
		{
			c = 1000 - a - b;
			if (pow(a, 2) + pow(b, 2) == pow(c, 2))
				return (a * b * c);
		}
	}
	return (-1);
}

int		main(void)
{
	int ans = pythagorean_product(1000);
	printf("%i\n", ans);
	return (0);
}
