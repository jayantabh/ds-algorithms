#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values

int fib_last_sum_mod(int64_t n, int mod)
{
	int fib, fib_n1 = 1, fib_n2 = 0, period = 0;
	
	if(n < mod)
	{
		if(n==0)
			fib = 0;
		else
			fib = 1;
		
		for(int i=2; i <= n; i++)
		{
			fib = (fib_n1 + fib_n2) % mod;
			fib_n2 = fib_n1;
			fib_n1 = fib;
		}
		
		return fib;
	}
	
	for(int64_t i=2;; i++)
	{
		fib = (fib_n1 + fib_n2) % mod;
		fib_n2 = fib_n1;
		fib_n1 = fib;
		if(fib_n2 == 0 && fib_n1 == 1)
		{
			period = i - 1;
			break;
		}
	}
	
	int temp = n % period;
	
	fib_n2 = 0;
	fib_n1 = 1;
	
	if(temp==0)
		fib = 0;
	else
		fib = 1;
	
	for(int64_t i=2; i <= temp; i++)
	{
		fib = (fib_n1 + fib_n2) % mod;
		fib_n2 = fib_n1;
		fib_n1 = fib;
	}
	
	return fib;
}

int fib_last_sum_sqrmod(int64_t n)
{
	return (fib_last_sum_mod(n, 10) * (fib_last_sum_mod(n, 10) + fib_last_sum_mod(n-1, 10))) % 10;
}

int main()
{
	int64_t num1;
	
	cin >> num1;
	cout << fib_last_sum_sqrmod(num1) << endl;
	
	return 0;
}