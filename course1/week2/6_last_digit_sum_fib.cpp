#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values

int fib_last_sum_mod(int64_t n)
{
	int fib, fib_n1 = 1, fib_n2 = 0, period = 60, temp = (n + 2) % period, mod = 10;
	
	if(temp == 1)
		fib = 1;
	else 
		fib = 10;
	
	for(int64_t i=2; i <= temp; i++)
	{
		fib = (fib_n1 + fib_n2) % mod;
		fib_n2 = fib_n1;
		fib_n1 = fib;
	}
	
	return (fib + 9)%10;
}

int main()
{
	int64_t num;
	
	cin >> num;
	cout << fib_last_sum_mod(num) << endl;
	
	return 0;
}