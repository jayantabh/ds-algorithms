#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int64_t binary_search_end(const vector<int64_t> &a, int64_t left, int64_t right, int64_t x) 
{
	int64_t mid = int64_t((left + right)/2);
	
	if(left + 1 >= right)
	{
		if(a[mid] < x)
		{
			return mid;
		}
		else
		{
			return mid - 1;
		}
	}

	if(a[mid] >= x)
	{
		return binary_search_end(a, left, mid, x);
	}
	else
	{
		return binary_search_end(a, mid + 1, right, x);
	}
}

int64_t binary_search_end_wrapper(const vector<int64_t> &a, int64_t x)
{
	return binary_search_end(a, 0, a.size(), x);
}

int64_t binary_search_start(const vector<int64_t> &a, int64_t left, int64_t right, int64_t x) 
{
	int64_t mid = int64_t((left + right)/2);
	
	if(left + 1 >= right)
	{
		if(a[mid] > x)
		{
			return mid;
		}
		else
		{
			return mid + 1;
		}
	}

	if(a[mid] > x)
	{
		return binary_search_start(a, left, mid, x);
	}
	else
	{
		return binary_search_start(a, mid + 1, right, x);
	}
}

int64_t binary_search_start_wrapper(const vector<int64_t> &a, int64_t x)
{
	return a.size() - binary_search_start(a, 0, a.size(), x);
}

int main()
{
	vector<int64_t> t = {1, 3, 6, 6, 6, 8, 9};
	
	int64_t x;
	
	std::cin >> x;

	std::cout << binary_search_end_wrapper(t, x) << std::endl;
	
	std::cout << binary_search_start_wrapper(t, x) << std::endl;
}