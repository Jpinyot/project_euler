/* Surprisingly there are only three numbers that can be written as the sum of fourth powers 	*/
/* of their digits: 																			*/
/* 1634 = 14 + 64 + 34 + 44 																	*/
/* 8208 = 84 + 24 + 04 + 84 																	*/
/* 9474 = 94 + 44 + 74 + 44 																	*/
/* As 1 = 14 is not a sum it is not included. 													*/
/* The sum of these numbers is 1634 + 8208 + 9474 = 19316. 										*/
/* Find the sum of all the numbers that can be written as the sum of fifth powers of their 		*/
/* digits. 																						*/
/* Solution = 443839 																			*/

#include <iostream>
#include <math.h>

using namespace std; 

int		sum_of_powers(int size)
{
	int				j;
	int				i;
	int				max_value = 999999;
	int				cnt;
	int				cnt_ret = 0;

	for (i = max_value; i > 1; i--)
	{
		cnt = 0;
		j = i;
			while (j)
			{
				cnt += pow(j % 10, size);
				j = j / 10;
			}
		if (cnt == i)
		{
			cnt_ret += i;
		}
	}
	return (cnt_ret);
}

int		main(void)
{
	int ans =  sum_of_powers(5);
	cout << ans << '\n';
	return (0);
}
