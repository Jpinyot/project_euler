/* A perfect number is a number for which the sum of its proper divisors is exactly equal 		*/
/* to the number. For example, the sum of the proper divisors of 28 would be 					*/
/* 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number. 							*/
/* A number n is called deficient if the sum of its proper divisors is less than n and it 		*/
/* is called abundant if this sum exceeds n. 													*/
/* As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that 		*/
/* can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can 	*/
/* be shown that all integers greater than 28123 can be written as the sum of two abundant 		*/
/* numbers. However, this upper limit cannot be reduced any further by analysis even though 	*/
/* it is known that the greatest number that cannot be expressed as the sum of two abundant 	*/
/* numbers is less than this limit. 															*/
/* Find the sum of all the positive integers which cannot be written as the sum of two 			*/
/* abundant numbers. 																			*/
/* Solution = 4179871 																			*/

#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

long	is_abundant(int limit)
{
	int		i;
	int		sum = 1;
	int		root = sqrt(limit);

	for(i = 2; i <= root; i++)
	{
		if (limit % i == 0)
		{
			if (i * i != limit)
				sum += i + limit / i;
			else
				sum += i;

		}
	}
	if (sum > limit)
		return (sum);
	return (0);
}

int		sum_non_sum_abundant(int limit)
{
	int					i;
	int					j = 0;
	int					sum;
	long				ret = 0;
	bool				check_abund[limit + 1];
	std::vector<int>	abundant_nums;

	std::fill_n(check_abund, limit, false);
	for (i = 1; i < limit; i++)
		if (is_abundant(i))
			abundant_nums.push_back(i);
	for (i = 0; i < abundant_nums.size(); i++)
	{
		for (j = i; j < abundant_nums.size(); j++)
		{
			if ((sum = abundant_nums[i] + abundant_nums[j]) > limit)
				break ;
			check_abund[sum] = true;
		}
	}
	for (i = 1; i <= limit; i++)
		if (check_abund[i] == false)
			ret += i;
	return (ret);
}


int		main(void)
{
	int ans = sum_non_sum_abundant(28123);
	std::cout << ans << '\n';
	return (0);
}
