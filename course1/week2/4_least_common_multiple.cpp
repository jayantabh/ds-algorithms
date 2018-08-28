#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values

int32_t gcd(int32_t num1, int32_t num2)
{	
	if(num2 == 0)
		return num1;
	
	return gcd(num2, num1 % num2);
}

int32_t lcm(int32_t num1, int32_t num2)
{
	return int32_t((num2/gcd(num1, num2))*num1);
}
	
int main()
{
	int32_t num1, num2;	
	
	cin >> num1 >> num2;
	
	if(num1 > num2)
		cout << lcm(num1, num2) << endl;
	else
		cout << lcm(num2, num1) << endl;
	
	return 0;
}