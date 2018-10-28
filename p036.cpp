/* The decimal number, 585 = 10010010012 (binary), is palindromic in both bases. 				*/
/* Find the sum of all numbers, less than one million, which are palindromic in base 			*/
/* 10 and base 2. 																				*/
/* (Please note that the palindromic number, in either base, may not include leading zeros.) 	*/
/* Solution = 872187 																			*/

#include <iostream>
#include <math.h>
#include <unistd.h>
#define TEST_N 1

using namespace std;

bool	is_palindrome(string str)
{
	int i = -1;
	int	j = str.size() - 1;

	while (str[++i] && str[i] == '0');
	while (str[i] && str[i] == str[j] && ++i <= --j);
	if (i >= j) return (true);
	return (false);
}

int		palindromi(int limit)
{
	int		i;
	int		cnt = 0;

	for (i = 0; i < limit; i++)
	{
		if (is_palindrome(to_string(i)))
		{
			if (is_palindrome(bitset<20>(i).to_string()))
				cnt += i;
		}
	}
	return (cnt);
}

int		main(void)
{
	int ans =  palindromi(1000000);
	cout << ans << '\n';
	return (0);
}
