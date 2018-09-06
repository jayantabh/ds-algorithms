#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values

int fib_last_sum_mod(int64_t n)
{
	int fib, fib_n1 = 1, fib_n2 = 0, period = 60, temp = (n + 2) % period, mod = 10;
	
	if(temp == 1)
		fib = 1;
	else if (n < 0)
		fib = 0;
	else
		fib = 10;
	
	for(int64_t i=2; i <= temp; i++)
	{
		fib = (fib_n1 + fib_n2) % mod;
		fib_n2 = fib_n1;
		fib_n1 = fib;
	}
	
	return fib - 1;
}

int fib_part_sum_mod(int64_t num1, int64_t num2)
{
	if(fib_last_sum_mod(num1-1) <= fib_last_sum_mod(num2))
		return fib_last_sum_mod(num2) - fib_last_sum_mod(num1-1);
	else 
		return 10 + (fib_last_sum_mod(num2) - fib_last_sum_mod(num1-1));
}

int main()
{
	int64_t num1, num2;
	
	cin >> num1 >> num2;
	cout << fib_part_sum_mod(num1, num2) << endl;
	
	return 0;
}