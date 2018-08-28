#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values
int32_t last_digit_fib(int32_t n)
{
	int32_t fib [n+1];
	fib[0] = 0;
	fib[1] = 1;
	
	if(n==1 || n==0)
		return fib[n];
	
	for(int32_t i=2; i<=n; i++)
		fib[i] = (fib[i-1] + fib[i-2])%10;
	
	return fib[n];
}

int main()
{
	int32_t n;	
	
	cin >> n;
	cout << last_digit_fib(n) << endl;
	
	return 0;
}