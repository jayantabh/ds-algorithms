#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values
int last_dig_sum_part_fib(int64_t m, int64_t n)
{
	int64_t fib [n+1];
	fib[0] = 0;
	fib[1] = 1;
	int sum = 0;
	
	if(m < 2)
		sum = 1;
	
	if(n==1 || n==0)
		return int(fib[n]);
	
	for(int64_t i=2; i<=n; i++)
	{
		fib[i] = (fib[i-1] + fib[i-2])%10;
		if(i>=m)
			sum = (sum + fib[i]) % 10;
	}
	
	return sum;
}

int main()
{
	int64_t num1, num2;	
	
	cin >> num1 >> num2;
	cout << last_dig_sum_part_fib(num1, num2) << endl;
	
	return 0;
}