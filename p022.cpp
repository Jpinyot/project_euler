/* Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing 		*/
/* over five-thousand first names, begin by sorting it into alphabetical order. Then working	*/
/* out the alphabetical value for each name, multiply this value by its alphabetical			*/
/* position in the list to obtain a name score. 												*/
/* For example, when the list is sorted into alphabetical order, COLIN, which is worth 			*/
/* 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a 			*/
/* score of 938 × 53 = 49714. 																	*/
/* What is the total of all the name scores in the file? 										*/
/* Solution = 871198282 																		*/

#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::string> str_split(std::string str, char c)
{
	std::vector<std::string>	list;
	std::stringstream			ss(str);
	std::string 				item;

	while (std::getline(ss, item, c)) {
		list.push_back(item);
	}
	return (list);
}

int	sum_name_score(void)
{
	int							sum;
	int							i;
	int							j = 1;
	int							ret = 0;
	std::ifstream				data("resources/res_p022.txt");
	std::stringstream			ss;
	std::vector<std::string>	names_txt;
	std::vector<int>			names;

	ss << data.rdbuf();
	names_txt = str_split(ss.str(), ',');
	std::sort(names_txt.begin(), names_txt.end());
	for (std::vector<std::string>::iterator it = names_txt.begin(); it != names_txt.end(); ++it)
	{
		sum = 0;
		for (i = 1; it->c_str()[i] != '\"'; i++)
			sum += it->c_str()[i] - 'A' + 1;
		ret += sum * j;
		j++;

	}
	return (ret);
}


int main(void)
{
	int ans = sum_name_score();
	std::cout << ans << '\n';
	return (0);
}
