#include <iostream>
#include <vector>

using std::vector;

vector<int32_t> optimal_summands(int32_t n) 
{
	vector<int32_t> summands;
	int32_t i = 1;
  
	while(n > 2*i)
	{
		n = n - i;
		summands.push_back(i++);
	}
  
	if(n != 0)
	{
		summands.push_back(n);
	}
  
	return summands;
}

int main() 
{
	int32_t n;
	std::cin >> n;
	vector<int32_t> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) 
	{
		std::cout << summands[i] << ' ';
	}
}
