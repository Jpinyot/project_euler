/* n! means n × (n − 1) × ... × 3 × 2 × 1 														*/
/* For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, 										*/
/* and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27. 				*/
/* Find the sum of the digits in the number 100! 												*/
/* Solution = 648 																				*/

#include <iostream>
#define MAX_LONG_NUM 200

int		factorial_mult(int *fac, int size, int n)
{
	int		carry = 0;
	int		prod;

	for (int i = 0; i < size; i++)
	{
		prod = fac[i] * n + carry;
		fac[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		fac[size] = carry % 10;
		carry = carry / 10;
		size++;
	}
	return (size);
}

int		sum_digits_factorial(int n)
{
	int		i;
	int		fact_size = 1;
	int		factorial[MAX_LONG_NUM];
	int		ret = 0;

	factorial[0] = 1;
	for (i = 2; i <= n; i++)
		fact_size = factorial_mult(factorial, fact_size, i);
	for (i = fact_size - 1; i >= 0; i--)
		ret += factorial[i];
	return (ret);
}


int main(void)
{
	int ans = sum_digits_factorial(100);
	std::cout << ans << '\n';
	return (0);
}
