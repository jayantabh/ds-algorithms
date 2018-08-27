#include <iostream>

int main()
{
	int n, number, max1 = 0, max2 = 0;
	int64_t product;
	
	std::cin >> n;
	for(int i = 0; i<n; i++)
	{
		std::cin >> number;
		if(number >= max1)
		{
			max2 = max1;
			max1 = number;
		}
		else if(number >= max2)
		{
			max2 = number;
		}
	}
	
	product = int64_t(max1) * int64_t(max2);
	
	std::cout << product << std::endl;
	
	return 0;
}