#include <iostream>
#include <vector>

using std::vector;

int get_change(int m, const vector<int> &denominations) 
{
	vector<int> MinNumberCoins((m + 1), 1001);
	int NumCoins = 0;
	
	MinNumberCoins[0] = 0;
	
	// for(int i = 0; i < MinNumberCoins.size(); ++i)
	// {
		// std::cout << MinNumberCoins[i] << std::endl;
	// }
	
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 0; j < denominations.size(); ++j)
		{
			if(i >= denominations[j])
			{
				NumCoins = MinNumberCoins[(i - denominations[j])] + 1;
				if(NumCoins < MinNumberCoins[i])
				{
					MinNumberCoins[i] = NumCoins;
				}
			}
			// std::cout << "Value: " << i << " Denomination: " << denominations[j] << " Minimum Coins: " << MinNumberCoins[i] << std::endl;
		}
		// std::cout << MinNumberCoins[i] << std::endl;
	}
		
	return MinNumberCoins[m];
}

int main() 
{
	int m;
	vector<int> denominations = {1,3,4};
	std::cin >> m;
	std::cout << get_change(m, denominations) << '\n';
}
