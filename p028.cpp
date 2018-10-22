/* Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 		*/
/* spiral is formed as follows: 																*/
/*			21 22 23 24 25																		*/
/* 			20  7  8  9 10 																		*/
/* 			19  6  1  2 11 																		*/
/* 			18  5  4  3 12 																		*/
/* 			17 16 15 14 13 																		*/
/* It can be verified that the sum of the numbers on the diagonals is 101. 						*/
/* What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in 			*/
/* the same way? 																				*/
/* Solution = 669171001 																		*/

#include <iostream>
#include <math.h>

using namespace std;

long	sum_diagonal_spiral(int size)
{
	int		i;
	long	cnt = 1;

	for (i = 3; i <= size; i+= 2)
		cnt += (4 * pow(i, 2) - 6 * (i - 1));
	return (cnt);
}

int		main(void)
{
	long ans =  sum_diagonal_spiral(1001);
	cout << ans << '\n';
	return (0);
}
