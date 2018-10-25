/* 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145. 								*/
/* Find the sum of all numbers which are equal to the sum of the factorial of their digits. 	*/
/* Note: as 1! = 1 and 2! = 2 are not sums they are not included. 								*/
/* Solution = 40730 																			*/

#include <iostream>

using namespace std;

int		sum_factorial_digits()
{
	int		i;
	int		j;
	int		fact[10];
	int		sum;
	int		ret = 0;

	fact[0] = 1;
	for (i = 1; i < 10; i++)
		fact[i] = fact[i - 1] * i;
	for (i = 140; i < 40586; i++)
	{
		sum = 0;
		j = i;
		while (j)
		{
			sum += fact[j % 10];
			j = j / 10;
		}
		if (sum == i)
			ret += i;
	}
	return (ret);
}

int		main(void)
{
	int ans = sum_factorial_digits();
	cout << ans << '\n';
	return (0);
}
