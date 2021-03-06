/* Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5. 						*/
/* If they are then placed in numerical order, with any repeats removed, we get the 			*/
/* following sequence of 15 distinct terms: 													*/
/* 4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125 								*/
/* How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100? */
/* Solution = 9183 																				*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int		terms_count(int limit)
{
	int				i;
	int				j;
	int				cnt = 1;
	vector<double>	seq;

	for (i = 2; i <= limit; i++)
		for (j = 2; j <= limit; j++)
			seq.push_back(pow(j,i));
	sort(seq.begin(), seq.end());
	for (i = 1; i < seq.size(); i++)
	{
		if (seq[i] != seq[i - 1])
			cnt++;
		/* cout << seq[i] << ' '; */
	}
	return (cnt);
}

int		main(void)
{
	int ans =  terms_count(100);
	cout << ans << '\n';
	return (0);
}
