#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) 
{
	int m = str1.size();
	int n = str2.size();
	int insertion, deletion, match, mismatch;
	
	vector<vector<int>> MinDis(m + 1);
	
	for(size_t i = 0; i < m + 1; ++i)
	{
		MinDis[i] = vector<int> (n + 1, i);
	}
	
	for(size_t i = 0; i < n + 1; ++i)
	{
		MinDis[0][i] = i;
	}
	
	for(size_t j = 1; j < n + 1; ++j)
	{
		for(size_t i = 1; i < m + 1; ++i)
		{
			insertion = MinDis[i][j - 1] + 1;
			deletion = MinDis[i - 1][j] + 1;
			match = MinDis[i - 1][j - 1];
			mismatch = MinDis[i - 1][j - 1] + 1;
			if(str1[i - 1] == str2[j - 1])
			{
				MinDis[i][j] = std::min(std::min(insertion, deletion), match);
			}
			else
			{
				MinDis[i][j] = std::min(std::min(insertion, deletion), mismatch);
			}
		}
	}
	
	return MinDis[m][n];
}

int main() 
{
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
	return 0;
}
