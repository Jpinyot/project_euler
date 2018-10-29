/* A natural number, N, that can be written as the sum and product of a given set of at 		*/
/* least two natural numbers, {a1, a2, ... , ak} is called a product-sum number: 				*/
/* N = a1 + a2 + ... + ak = a1 × a2 × ... × ak. 												*/
/* For example, 6 = 1 + 2 + 3 = 1 × 2 × 3. 														*/
/* For a given set of size, k, we shall call the smallest N with this property a minimal 		*/
/* product-sum number. The minimal product-sum numbers for sets of size, k = 2, 3, 4, 5, 		*/
/* and 6 are as follows. 																		*/
/* 		k=2: 4 = 2 × 2 = 2 + 2 																	*/
/* 		k=3: 6 = 1 × 2 × 3 = 1 + 2 + 3 															*/
/* 		k=4: 8 = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4 													*/
/* 		k=5: 8 = 1 × 1 × 2 × 2 × 2 = 1 + 1 + 2 + 2 + 2 											*/
/* 		k=6: 12 = 1 × 1 × 1 × 1 × 2 × 6 = 1 + 1 + 1 + 1 + 2 + 6 								*/
/* Hence for 2≤k≤6, the sum of all the minimal product-sum numbers is 4+6+8+12 = 30; note 		*/
/* that 8 is only counted once in the sum. 														*/
/* In fact, as the complete set of minimal product-sum numbers for 2≤k≤12 is 					*/
/* {4, 6, 8, 12, 15, 16}, the sum is 61. 														*/
/* What is the sum of all the minimal product-sum numbers for 2≤k≤12000? 						*/
/* Solution = 7587457 																			*/

#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <numeric>

using namespace std;

int			limit = 12000;
vector<int>	num;

void	producr_sum(int number, int sum, int product, int start)
{
    int k = number - sum + product;
    if (k < limit)
	{
        if (number < num[k])
            num[k] = number;
        for (int i = start; i < limit / number * 2; ++i)
            producr_sum(number * i, sum + i, product + 1, i);
    }
}
string	product_sum(void)
{
	for (int i = 0; i < limit; ++i)
		num.push_back(limit * 2);
	producr_sum(1, 1, 1, 2);
	set<int> ns(num.begin() + 2, num.end());
	return (to_string(accumulate(ns.begin(), ns.end(), 0)));
}

int		main(void)
{
	string ans = product_sum();
	cout << ans << '\n';
	return (0);
}
