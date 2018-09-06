#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;

int64_t get_optimal_value(vector<int32_t> profit, vector<int32_t> clicks) 
{
	int64_t value = 0;
	
	int num = profit.size();
	
	std::sort(profit.begin(), profit.end(), std::greater<int32_t>());
	std::sort(clicks.begin(), clicks.end(), std::greater<int32_t>());
	
	for(auto itr = 0; itr < num; ++itr)
	{
		value += int64_t(profit[itr]) * int64_t(clicks[itr]);
	}
	
	return value;
}

/*
int stress_test()
{	
	srand(time(NULL));
	
	int n;
	int32_t capacity;
	double optimal_value = 0.0;
	int test_number = 1;
	int k = 0;
	
	while(++k <= 30)
	{
		n = (std::rand() % 10) + 1;
		capacity = (std::rand() % 50) + 1;
		
		vector<int32_t> values(n);
		vector<int32_t> weights(n);
		
		for(auto i=0; i<n; ++i)
		{
			values[i] = (std::rand() % 30) + 1;
			weights[i] = (std::rand() % 30) + 1;
		}
		
		optimal_value = get_optimal_value(capacity, weights, values);
		
		std::cout << "Test: " << test_number << "; Number of elements: " << n << "; Capacity: " 
		          << capacity << "; Optimal Value: " << optimal_value << "\n";
		
		for(auto j=0; j<n; j++)
		{
			std::cout << "Value[" << j << "]: " << values[j] 
			          << "; Weight[" << j << "]: " << weights[j] 
					  << "; ValuePerWeight[" << j << "]: " << double(values[j])/weights[j] << "\n";
		}
		
		test_number += 1;
	}
	
    return 0;
}

int main()
{
	std::cout<<"Foo\n";
	stress_test();
	std::cout<<"Bar\n";
	return 0;
}
*/

int main() 
{
	int n;
	std::cin >> n;
	vector<int32_t> profit(n);
	vector<int32_t> clicks(n);
	for (int i = 0; i < n; i++) 
	{
		std::cin >> profit[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		 std::cin >> clicks[i];
	}
	
	int64_t optimal_value = get_optimal_value(profit, clicks);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
