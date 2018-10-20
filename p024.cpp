/* A permutation is an ordered arrangement of objects. For example, 3124 is one possible 		*/
/* permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically 	*/
/* or alphabetically, we call it lexicographic order. The lexicographic permutations of 		*/
/* 0, 1 and 2 are: 																				*/
/* 012   021   102   120   201   210 															*/
/* What is the millionth lexicographic permutation of the digits 								*/
/* 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9? 															*/
/* Solution = 2783918469 																		*/

#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int>	get_permutation(int size, int limit)
{
	int 				i;
	int					cnt = 0;
	std::vector<int>	str;

	for (i = 0; i <= size; i++)
		str.push_back(i);

	while (++cnt < limit)
		std::next_permutation(str.begin(), str.end());
	return (str);
}

int			main(void)
{
	std::vector<int> str = get_permutation(9, 1000000);
	for(std::vector<int>::iterator it = str.begin(); it != str.end(); ++it)
		std::cout << *it;
	std::cout << "\n";
	return (0);
}
