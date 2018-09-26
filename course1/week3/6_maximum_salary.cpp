#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <functional>

using std::vector;
using std::string;

bool compare2(const string& a, const string& b)
{
	if(a + b > b + a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string largest_number(vector<string> a) 
{
	std::sort(a.begin(), a.end(), compare2);
	
	std::stringstream ret;
  
	for (size_t i = 0; i < a.size(); i++) 
	{
		ret << a[i];
	}
	
	string result;
	ret >> result;
	return result;
}

int main() 
{
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); ++i) 
	{
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
}
