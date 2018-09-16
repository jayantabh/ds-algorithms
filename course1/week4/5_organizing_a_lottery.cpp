#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int64_t binary_search_end(const vector<int64_t> &a, int64_t left, int64_t right, int64_t x) 
{
	int64_t mid = int64_t((left + right)/2);
	
	// std::cout << x << " :: " << left << " :: " << right << " :: " << mid << std::endl;
	
	if(left + 1 == right)
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
	else if(left >= right)
	{	
		return right - 1;
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
	return binary_search_end(a, 0, a.size(), x) + 1;
}

int64_t binary_search_start(const vector<int64_t> &a, int64_t left, int64_t right, int64_t x) 
{
	int64_t mid = int64_t((left + right)/2);
	
	// std::cout << x << " :: " << left << " :: " << right << " :: " << mid << std::endl;
	
	if(left + 1 == right)
	{
		if(a[mid] > x)
		{
			// std::cout << "Mid Returned: " << a[mid];
			return mid;
		}
		else
		{
			// std::cout << "Mid + 1, Returned: " << a[mid];
			return mid + 1;
		}
	}
	else if(left >= right)
	{	
		return right;
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


vector<int64_t> fast_count_segments(vector<int64_t> starts, vector<int64_t> ends, vector<int64_t> points) 
{
	vector<int64_t> cnt(points.size());
	
	size_t start_greater = 0, 
		   end_smaller = 0;
	
	std::sort(starts.begin(), starts.end(), std::less<int64_t>());
	
	std::sort(ends.begin(), ends.end(), std::less<int64_t>());
	
	// std::cout << std::endl;
	
	for(size_t p = 0; p < points.size(); ++p)
	{
		// std::cout << "Point: " << p << " ";
		start_greater = binary_search_start_wrapper(starts, points[p]);
		end_smaller = binary_search_end_wrapper(ends, points[p]);
		// std::cout << starts.size() << " " << start_greater << " " << end_smaller << " ";
		cnt[p] = (starts.size() - start_greater - end_smaller);
	}
	
	// std::cout << std::endl;
	
	return cnt;
}

vector<int64_t> naive_count_segments(vector<int64_t> starts, vector<int64_t> ends, vector<int64_t> points) 
{
	vector<int64_t> cnt(points.size());
	for (size_t i = 0; i < points.size(); i++) 
	{
		for (size_t j = 0; j < starts.size(); j++) 
		{
			cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
		}
	}
	return cnt;
}

int main() 
{
	int64_t n, m;
	std::cin >> n >> m;
	vector<int64_t> starts(n), ends(n);
	
	for (size_t i = 0; i < starts.size(); i++) 
	{
		std::cin >> starts[i] >> ends[i];
	}
  
	vector<int64_t> points(m);
	
	for (size_t i = 0; i < points.size(); i++) 
	{
		std::cin >> points[i];
	}
	
	//use fast_count_segments
  
	vector<int64_t> cnt = fast_count_segments(starts, ends, points);
	for (size_t i = 0; i < cnt.size(); i++) 
	{
		std::cout << cnt[i] << ' ';
	}
}


