/* n England the currency is made up of pound, £, and pence, p, and there are eight coins 		*/
/* in general circulation: 																		*/
/* 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p). 											*/
/* It is possible to make £2 in the following way: 												*/
/* 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p 													*/
/* How many different ways can £2 be made using any number of coins? 							*/
/* Solution = 73682 																			*/

#include <iostream>
#include <vector>

template<typename T>
std::vector<T>& operator << (std::vector<T>& v, const T & item)
{
    v.push_back(item);  return v;
}

template<typename T>
std::vector<T>& operator , (std::vector<T>& v, const T & item)
{
    v.push_back(item);  return v;
}

unsigned int denom_func(int n, std::vector<int> &denoms)
{
	std::vector<int> tmp_denoms;

    if (denoms.empty() || n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
	{
		tmp_denoms = denoms;
        denoms.erase(denoms.begin());
        return denom_func(n - tmp_denoms.front(), tmp_denoms) + denom_func(n, denoms);
    }
}

int			coins(int price) {
    std::vector<int> ans;
	ans << 1,2,5,10,20,50,100,200;
    return (denom_func(price, ans));
}

int		main(void)
{
	int ans = coins(200);
	std::cout << ans << '\n';
	return (0);
}
