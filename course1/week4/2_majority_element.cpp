#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int64_t get_majority_element(vector<int64_t> &a, int64_t left, int64_t right) 
{
	int64_t mid, major_left = -1, major_right = -1, count = 0; 
	
	// std::cout << "Length:" << a.size() << left << right << std::endl;
	
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
  
	mid = int((left + right)/2);
	major_left = get_majority_element(a, left, mid);
	major_right = get_majority_element(a, mid, right);
	
	for(size_t i = left; i < right; ++i)
	{
		if(a[i] == major_left)
		{
			count += 1;
		}
	}
	
	if(count > int((right - left)/2))
	{
		//std::cout << "Left:" << major_left << std::endl;
		return major_left;
	}
	
	count = 0;
	
	for(size_t i = left; i<right; ++i)
	{
		if(a[i] == major_right)
		{
			count += 1;
		}
	}
	
	if(count > int((right - left)/2))
	{
		// std::cout << "Right:" << major_right << std::endl;
		return major_right;
	}
	
	return -1;
}

int main() 
{
	int64_t n;
	std::cin >> n;
	vector<int64_t> a(n);
	
	for(size_t i = 0; i < a.size(); ++i) 
	{
		std::cin >> a[i];
	}
	
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
