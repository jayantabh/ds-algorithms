#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int64_t> partition3(vector<int64_t> &a, int64_t l, int64_t r, vector<int64_t> &pos) 
{
	// for(size_t temp = 0; temp < a.size(); ++temp)
	// {
		// std::cout << a[temp] << " ";
	// }
	
	// std::cout << std::endl;
	
	int64_t x = a[l];
	int64_t j = l;
	int64_t k = l;
	
	// std::cout << "Partition Parameters: " << j << " " << k << std::endl; 
	
	// std::cout << "Function Call\n";
 	
	for (int64_t i = l + 1; i <= r; i++) 
	{
		if (a[i] < x) 
		{
			++k;
			++j;
			swap(a[i], a[k]);
			swap(a[k], a[j]);
		}
		else if (a[i] == x)
		{
			++k;
			swap(a[i], a[k]);
		}
		// std::cout << "Initial: " << j << "Final: " << k << std::endl;
	}
	
	swap(a[l], a[j]);
	
	// std::cout << "After Call: Initial: " << j << "Final: " << k << std::endl;
	
	pos[0] = j;
	pos[1] = k;
	
	return pos;
}

void randomized_quick_sort(vector<int64_t> &a, int64_t l, int64_t r) 
{
	if (l >= r) 
	{
		// std::cout << "No Processing" << std::endl;
		return;
	}
	
	int64_t k = l + rand() % (r - l + 1);
	
	swap(a[l], a[k]);
	
	vector<int64_t> m;
	
	m.push_back(0);
	m.push_back(1);
	
	// std::cout << "Test\n";
	
	m = partition3(a, l, r, m);
	
	// std::cout << "Partition: " << m[0] << " " << m[1] << std::endl; 
	
	int temp;
	
	// if(m[0] == 0 && m[1]==2)
		// std::cin >> temp;
	
	randomized_quick_sort(a, l, m[0] - 1);
	randomized_quick_sort(a, m[1] + 1, r);
}

int main() 
{
	int64_t n;
	std::cin >> n;
	vector<int64_t> a(n);
	
	for (size_t i = 0; i < a.size(); ++i) 
	{
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	
	for (size_t i = 0; i < a.size(); ++i) 
	{
		std::cout << a[i] << ' ';
	}
}
