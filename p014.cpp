/* The following iterative sequence is defined for the set of positive integers: 				*/
/* n → n/2 (n is even) 																			*/
/* n → 3n + 1 (n is odd) 																		*/
/* Using the rule above and starting with 13, we generate the following sequence: 				*/
/* 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1 													*/
/* It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 	*/
/* Although it has not been proved yet (Collatz Problem), it is thought that all starting 		*/
/* numbers finish at 1. 																		*/
/* Which starting number, under one million, produces the longest chain? 						*/
/* NOTE: Once the chain starts the terms are allowed to go above one million. 					*/

#include <stdio.h>
#include <unistd.h>
long values[100000000000];

typedef struct	s_num
{
	int		val;
	int		n_nodes;
}				t_num;

int		calculate_chain(long n)
{
	if (values[n])
		return (values[n]);
	if (n % 2 == 0)
		values[n] = 1 + calculate_chain(n / 2);
	else
		values[n] = 2 + calculate_chain((3 * n + 1) / 2);
	return (values[n]);
}

int		longest_chain(int limit)
{
	t_num	ret;
	int		val;
	int		cnt;

	ret.val = 1;
	ret.n_nodes = 0;
	values[1] = 1;
	for (int i = limit / 2; i < limit; i++)
	{
		val = i;
		cnt = calculate_chain(i);
		if (cnt > ret.n_nodes)
		{
			ret.n_nodes = cnt;
			ret.val = i;
		}
	}
	return (ret.val);
}

int		main(void)
{
	int ans = longest_chain(1000000);
	printf("%i\n", ans);
	return (0);
}
