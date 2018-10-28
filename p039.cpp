/* If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, 		*/
/* there are exactly three solutions for p = 120. 												*/
/* {20,48,52}, {24,45,51}, {30,40,50} 															*/
/* For which value of p ≤ 1000, is the number of solutions maximised? 							*/
/* Solution = 840 																				*/

#include <iostream>

using namespace std;

int		triangle(int limit)
{
	int		tri_cnt = 0;
	int		cnt;
	int		tri = 0;

	for (int i = 2; i <= 1000; i += 2) {
		cnt = 0;
		for (int a = 2; a < i/3; a++)
			if (i * (i - (2 * a)) % (2 * (i - a)) == 0)
				cnt++;
		if (cnt > tri_cnt)
		{
			tri_cnt = cnt;
			tri = i;
		}
	}
    return (tri);
}

int		main(void)
{
	int ans = triangle(1000);
	cout << ans << '\n';
	return (0);
}
