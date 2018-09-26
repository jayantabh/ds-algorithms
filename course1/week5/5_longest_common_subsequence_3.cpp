#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int lcs3(const vector<int32_t> &v1, const vector<int32_t> &v2, const vector<int32_t> &v3) 
{
	int m = v1.size();
	int n = v2.size();
	int p = v3.size();
	int op1, op2, op3, op4, op5, op6, match;
	
	vector<vector<vector<int>>> Matrix(m + 1);
	
	// std::cout << "Phase 1\n";
	
	for(size_t i = 0; i < m + 1; ++i)
	{
		Matrix[i] = vector<vector<int>> (n + 1);
		for(size_t j = 0; j < n + 1; ++j)
		{
			Matrix[i][j] = vector<int> (p + 1, 0);
		}
	}
	
	// std::cout << "Phase 2\n";
	
	for(size_t k = 0; k < p + 1; ++k)
	{
		for(size_t j = 1; j < n + 1; ++j)
		{
			for(size_t i = 1; i < m + 1; ++i)
			{
				// std::cout << "Phase 3\n";
				op1 = Matrix[i][j - 1][k];
				op2 = Matrix[i - 1][j][k];
				op3 = Matrix[i][j][k - 1];
				op4 = Matrix[i - 1][j - 1][k];
				op5 = Matrix[i - 1][j][k - 1];
				op6 = Matrix[i][j - 1][k - 1];
				match = Matrix[i - 1][j - 1][k - 1] + 1;
				if(v1[i - 1] == v2[j - 1] && v1[i - 1] == v3[k - 1])
				{
					Matrix[i][j][k] = match;
				}
				else
				{
					Matrix[i][j][k] = std::max(std::max(std::max(std::max(std::max(op1, op2),op3),op4),op5),op6);
				}
			}
		}
	}
	
	return Matrix[m][n][p];
}

int main() 
{
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	
	for (size_t i = 0; i < an; i++) 
	{
		std::cin >> a[i];
	}
	
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	
	for (size_t i = 0; i < bn; i++) 
	{
		std::cin >> b[i];
	}
	
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	
	for (size_t i = 0; i < cn; i++) 
	{
		std::cin >> c[i];
	}
	
	std::cout << lcs3(a, b, c) << std::endl;
}

