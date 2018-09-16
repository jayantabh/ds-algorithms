#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using std::vector;

int64_t binary_search(const vector<int64_t> &a, int64_t left, int64_t right, int64_t x) 
{
	int64_t mid = int64_t((left + right)/2);
	vector<int64_t> b;
	
	//int l;
	//std::cin >> l; 
	
	//std::cout<<left<<" "<<mid<<" "<<right<<" "<<x<<"\n";
	
	if(a[mid] == x)
	{
		return mid;
	}
	else if(mid <= 0 || mid >= right)
	{
		return -1;
	}
	else if(a[mid] > x)
	{
		return binary_search(a, left, mid, x);
	}
	else
	{
		return binary_search(a, mid + 1, right, x);
	}
}

int64_t linear_search(const vector<int64_t> &a, int64_t x) 
{
	for (size_t i = 0; i < a.size(); ++i) 
	{
		if (a[i] == x) return i;
	}
	return -1;
}

int main() 
{
	int64_t n;
	std::cin >> n;
	vector<int64_t> a(n);
  
	for (size_t i = 0; i < a.size(); i++) 
	{
		std::cin >> a[i];
	}
  
	int64_t m;
	std::cin >> m;
	vector<int64_t> b(m);
  
	for (size_t i = 0; i < m; ++i) 
	{
		std::cin >> b[i];
	}
  
	for (size_t i = 0; i < m; ++i) 
	{
		std::cout << binary_search(a, 0, a.size(), b[i]) << ' ';
	}
}

/*
int stress_test()
{
	int n = 0, s = 0, bin = 0, lin = 0;
	int flag = 0;
	
	while(true)
	{	
		srand (time(NULL));
		n = rand()%1000 + 1;
		vector<int64_t> a(n);
		for(size_t j=0; j<n; ++j)
		{
			a[j] = rand()%100000 + 1;
		}
		
		std::sort(a.begin(), a.end(), std::less<int>());
		
		for(size_t k=0; k<1000; k++)
		{
			s = a[rand()%n];
			bin = binary_search(a, 0, a.size(), s);
			lin = linear_search(a,s);
			if(bin != lin)
			{	
				for(size_t i=0; i<a.size(); ++i)
				{
					std::cout << a[i] << " ";
				}
				std::cout << "\n" << s << "::" << bin << "::" << lin << std::endl;
				std::cin >> flag;
				if(flag == 0)
				{
					break;
				}
			}
		}
	}
}


int main()
{
	stress_test();
}
*/
