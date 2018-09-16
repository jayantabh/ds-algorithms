#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) 
{ 
	string answer = "";
	int maxDigit = a.size() + 1;
	a[maxDigit] = "0";
	
	while(a.size() > 0) 
	{
		maxDigit = a.size();
		for(size_t j = 0; j < a.size(); ++j)
		{
			if(int(a[j][0]) >= int(a[maxDigit][0]))
				maxDigit = j;
		}
		
		if(a[maxDigit] != "0")
			answer.append(a[maxDigit]);
		
		a.erase(a.begin() + maxDigit);
	}
	
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
	
	for (size_t i = 0; i < a.size(); i++) 
	{
		std::cin >> a[i];
	}
	
	std::cout << largest_number(a);
}
