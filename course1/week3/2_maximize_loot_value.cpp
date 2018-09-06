#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using std::vector;

struct item
{
	int32_t weight;
	int32_t value;
	double valueperweight;
};

double get_optimal_value(int32_t capacity, vector<int32_t> weights, vector<int32_t> values) 
{
	double value = 0.0;
  
	/*
	vector<int> valueperweight(weights.size()); 
	
	std::transform(values.begin(), values.end(), 
				   weights.begin(), std::back_inserter(valueperweight),
				   std::divides<int>());
	*/
	
	vector<item> items(weights.size()); 
	
	for(auto i = 0; i < weights.size(); ++i)
	{
		items[i].weight = weights[i];
		//std::cout << i << ": Weight - " << weights[i] << " ; " << items[i].weight << "\n";
		
		items[i].value = values[i];
		//std::cout << i << ": Value - " << values[i] << " ; " << items[i].value << "\n";
		
		items[i].valueperweight = double(items[i].value)/items[i].weight;
		//std::cout << i << ": Value Per Weight - " << items[i].value/items[i].weight << " ; " 
		//          << items[i].valueperweight << "\n";
	}

	/*
	for(auto i = 0; i < items.size(); ++i)
	{	
		std::cout << items[i].valueperweight << std::endl;
	}
	*/
	
	
	std::sort(items.begin(), items.end(), 
	          [](auto const &a, auto const &b) { return a.valueperweight > b.valueperweight; });
	
	for(auto itr = 0; capacity > 0 && itr < items.size(); ++itr)
	{
		if(capacity >= items[itr].weight)
		{
			capacity -= items[itr].weight;
			value += double(items[itr].value);
		}
		else
		{
			value += double(capacity * items[itr].valueperweight);
			capacity = 0;
		}
		
		//std::cout << "Value: " << value << " Capacity: " << capacity << "\n"; 
	}
	
	return value;
}

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

/*
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
	int32_t capacity;
	std::cin >> n >> capacity;
	vector<int32_t> values(n);
	vector<int32_t> weights(n);
	for (int i = 0; i < n; i++) 
	{
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
