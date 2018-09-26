#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

int lcs2(const vector<int32_t> &v1, const vector<int32_t> &v2) 
{
	int m = v1.size();
	int n = v2.size();
	int insertion, deletion, match;
	
	vector<vector<int>> Matrix(m + 1);
	
	for(size_t i = 0; i < m + 1; ++i)
	{
		Matrix[i] = vector<int> (n + 1, 0);
	}

	for(size_t j = 1; j < n + 1; ++j)
	{
		for(size_t i = 1; i < m + 1; ++i)
		{
			insertion = Matrix[i][j - 1];
			deletion = Matrix[i - 1][j];
			match = Matrix[i - 1][j - 1] + 1;
			if(v1[i - 1] == v2[j - 1])
			{
				Matrix[i][j] = match;
			}
			else
			{
				Matrix[i][j] = std::max(insertion, deletion);
			}
		}
	}
	
	return Matrix[m][n];
}

int main() 
{
	size_t n;
	std::cin >> n;
	vector<int32_t> a(n);
	
	for (size_t i = 0; i < n; i++) 
	{
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int32_t> b(m);
	for (size_t i = 0; i < m; i++) 
	{
		std::cin >> b[i];
	}

	std::cout << lcs2(a, b) << std::endl;
}
