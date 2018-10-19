/* Starting in the top left corner of a 2×2 grid, and only being able to move to the 			*/
/* right and down, there are exactly 6 routes to the bottom right corner. 						*/
/* How many such routes are there through a 20×20 grid? 										*/
/* Solution = 137846528820																		*/

#include <stdio.h>
#include <math.h>

unsigned long long	routes_counter(int size)
{
	unsigned long long ret = 1;

	for (int i = 1; i <= size; i++)
		ret = (ret * (i + size)) / i;
	return (ret);
}

int		main(void)
{
	unsigned long long ans = routes_counter(20);
	printf("%lld\n", ans);
	return (0);
}
