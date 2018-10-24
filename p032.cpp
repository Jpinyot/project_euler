/* We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to 	*/
/* n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital. 			*/
/* The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, 		*/
/* multiplier, and product is 1 through 9 pandigital. 											*/
/* Find the sum of all products whose multiplicand/multiplier/product identity can be 			*/
/* written as a 1 through 9 pandigital. 														*/
/* HINT: Some products can be obtained in more than one way so be sure to only include 			*/
/* it once in your sum. 																		*/
/* Solution = 45228 																			*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int		is_pandigital(int val1, int val2)
{
	int		prod = val1 * val2;
	int		str[10];

	for (int i = 0; i < 10; i++)
		str[i] = 0;
	while (val1 || val2 || prod)
	{
		if (val1){ str[val1 % 10] += 1; val1 = val1 / 10;}
		if (val2){ str[val2 % 10] += 1; val2 = val2 / 10;}
		if (prod){ str[prod % 10] += 1; prod = prod / 10;}
	}
	if (str[0])
		return (0);
	for (int i = 1; i < 10; i++)
		if (str[i] != 1)
			return (0);
	return (1);
}

int		sum_pandigital(void)
{
	int			i;
	int			j;
	vector<int>	prod;
	int			ret = 0;

	for (i = 2; i < 9876; i++)
		for (j = 123; j < 9876 / i; j++)
			if (is_pandigital(i, j))
				prod.push_back(i * j);
	sort(prod.begin(), prod.end());
	ret += prod[0];
	for (i = 1; i < prod.size(); i ++)
		if (prod[i] != prod[i - 1])
			ret += prod[i];
	return (ret);
}

int		main(void)
{
	int ans = sum_pandigital();
	cout << ans << '\n';
	return (0);
}
