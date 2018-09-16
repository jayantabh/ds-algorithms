#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool compareByLength(const string &a, const string &b)
{
	size_t i=0;
	
	std::cout << a << "<>" << a.size() << "<>" << b << "<>" << b.size() << "\n";
	
	for(; i < std::min(a.size(), b.size()); ++i)
	{
		if(int(a[i]) < int(b[i]))
			return false;
		else if (int(a[i]) > int(b[i]))
			return true;
	}
	
	std::cout << "::Phase 1::\n";
	
	if(a.size() < b.size())
	{
		return  b[b.end()] < a[0];
	}
	else if (a.size() > b.size())
	{
		return  a[a.end()] < b[0];
	}
	else return true;
}

string largest_number(vector<string> a) 
{
	//std::cout << "::Segment 1::\n";
	
	std::sort(a.begin(), a.end(), compareByLength);
	
	//std::cout << "::Segment 2::\n";
	
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
