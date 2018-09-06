#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values

int number_of_coins(int num)
{
	int tens = 0, fives = 0, ones = 0;
	
	tens = int(num/10);
	num = num - tens * 10;
	fives = int(num/5);
	num = num - fives * 5;
	ones = num;
	
	return tens + fives + ones;
}

int main()
{
	int num;
	
	cin >> num;
	cout << number_of_coins(num) << endl;
	
	return 0;
}