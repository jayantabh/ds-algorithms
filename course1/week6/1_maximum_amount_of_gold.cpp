#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int optimal_weight(int W, const vector<int> &w) 
{
	int current_value = 0;
	int n = w.size();
	vector<vector<int>> value(W + 1);
	
	for(size_t i = 0; i <= W; ++i)
	{
		value[i] = vector<int> (n + 1, 0);
	}

	for(size_t i = 1; i < n + 1; ++i)
	{
		for(size_t j = 1; j < W + 1; ++j)
		{
			value[j][i] = value[j][i - 1];
			
			if(w[i - 1] <= j)
			{
				current_value = value[(j - w[i - 1])][i - 1] + w[i - 1];
				if(current_value > value[j][i])
				{
					value[j][i] = current_value;
				}
			}
		}
	}
	
	return value[W][n];
}

int main() 
{
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	
	for (int i = 0; i < n; i++) 
	{
		std::cin >> w[i];
	}
	
	std::cout << optimal_weight(W, w) << '\n';
}
