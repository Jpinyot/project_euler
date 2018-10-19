/* By starting at the top of the triangle below and moving to adjacent numbers on the row 		*/
/* below, the maximum total from top to bottom is 23. 											*/
/*					 	   3 																	*/
/*					 	  7 4 																	*/
/*					 	 2 4 6 																	*/
/*					 	8 5 9 3 																*/
/* That is, 3 + 7 + 4 + 9 = 23. 																*/
/* Find the maximum total from top to bottom of the triangle below: 							*/
/* Solution = 1074 																				*/

#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

std::vector<int> split_nums(std::string str, char c)
{
	std::vector<int>			ret;
    std::vector<std::string>	list;
    std::stringstream			ss(str);
    std::string					item;

    while (std::getline(ss, item, c)) {
        list.push_back(item);
    }
	for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
		ret.push_back(atoi(it->c_str()));
	return (ret);
}


int	biggest_sum()
{
	int		size = 0;
	int		i = 0;
	int		j;
	std::vector< std::string >		triangle;
	std::string						line;
	std::ifstream					file("resources/res_p018.txt");
	std::vector< std::vector<int> >	values;
	std::vector<int>				nums;

	/* EXTRACT FILE */
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			triangle.push_back(line);
		}
	}
	else
		return (-1);
	file.close();
	size = triangle.size() - 1;
	int		routes[size];
	/* ATOI */
	for (i = 0; i < size; i++)
	{
		nums = split_nums(triangle.at(i), ' ');
		values.push_back(nums);
	}
	/* INITIALIZE VALUES AS LAST ROW */
	for (i = 0; i < size; i++)
		routes[i] = values[size - 1][i];
	/* FROM SECOND LAST ROW TO THE TOP */
	for (i = size - 2; i >= 0; --i)
		for (j = 0; j <= i; j++)
			routes[j] = values[i][j] + std::max(routes[j], routes[j + 1]);
	return (routes[0]);
}

int main(void)
{
	int ans = biggest_sum();
	std::cout << ans << '\n';
	return (0);
}
