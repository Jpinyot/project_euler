/* A palindromic number reads the same both ways. The largest palindrome made from the product	*/
/* of two 2-digit numbers is 9009 = 91 × 99. 													*/
/* Find the largest palindrome made from the product of two 3-digit numbers. 					*/
/* Solution = 906609																			*/

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

char is_palindrome(int num) {
    int tmp = num;
    int sum = 0;
    int r;

    while (tmp)
	{
        r = tmp % 10;
        tmp = tmp / 10;
        sum = sum * 10 + r;
    }
    if (num == sum)
		return (1);
	return (0);
}

int		max_palindrome(int size)
{	
	std::vector<int>	list;
	int					n1;
	int					n2;
	int					max_value;

	max_value = 0;
	for (int i = 0; i < size; i++)
		max_value = max_value * 10 + 9;
	n1 = max_value;
	while (n1 > max_value / 10)
	{
		n2 = max_value;
		while (n2 > max_value / 10)
		{
			if (is_palindrome(n1 * n2))
				list.push_back(n1 * n2);
			n2--;
		}
		n1--;
	}
	return (list[std::distance(list.begin(), max_element(std::begin(list), std::end(list)))]);
}


int		main(void)
{
	int	ans = max_palindrome(3);
	printf("%i", ans);
	return (0);
}
