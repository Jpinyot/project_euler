/* Take the number 192 and multiply it by each of 1, 2, and 3: 									*/
/* 		192 × 1 = 192 																			*/
/* 		192 × 2 = 384 																			*/
/* 		192 × 3 = 576 																			*/
/* By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 			*/
/* 192384576 the concatenated product of 192 and (1,2,3) 										*/
/* The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving 	*/
/* the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5). 			*/
/* What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated 	*/
/* product of an integer with (1,2, ... , n) where n > 1? 										*/
/* Solution = 932718654 																		*/

#include <iostream>

using namespace std;

bool	is_pandigital(string num)
{
	int		i;

	sort(num.begin(), num.end());
	if (num[0] == '0')
		return (false);
	for (i = 1; i < num.size(); i++)
		if (num[i] == num[i - 1])
			return (false);
	return (true);
}

string		pandigital_mult(void)
{
	int		i;
	int		j;
	string	pand;
	string	num;

	for (i = 2; i < 9999; i++)
	{
		num = to_string(i);
		for (j = 2; num.size() < 9; j++)
		{
			num.append(to_string(i * j));
		}
		if (num.size() == 9 && is_pandigital(num))
			pand = num;
	}
	return (pand);
}

int		main(void)
{
	string ans = pandigital_mult();
	cout << ans << '\n';
	return (0);
}
