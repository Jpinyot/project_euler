/* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 	*/
/* 3 + 3 + 5 + 4 + 4 = 19 letters used in total. 												*/
/* If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how 	*/
/* many letters would be used? 																	*/
/* NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) 		*/
/* contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of 		*/
/* "and" when writing out numbers is in compliance with British usage. 							*/
/* Solution = 21124																				*/

#include <stdio.h>

int		count_char_to(void)
{
	int cnt = 0;

	/* 1 to 9 */
	cnt += 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4;
	/* 10 to 19 */
	cnt += 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8;
	/* 20 to 99 */
	cnt += 10*(6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) + 8*36;
	/* 100 to 999 */
	cnt += 36*100;
	cnt += 9*854;
	cnt +=  7*9;
	cnt += 891*10;
	/* 1000 */
	cnt += 11;
	return (cnt);
}

int		main(void)
{
	int	ans = count_char_to();
	printf("%i\n", ans);
	return (0);
}
