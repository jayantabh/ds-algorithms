#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values
int last_dig_sqrsum_fib(int64_t n)
{
	int64_t fib, fib_n1, fib_n2;
	fib_n2 = 0;
	fib_n1 = 1;
	int sum = 1;
	
	if(n==1 || n==0)
		return int(fib_n1);
	
	for(int64_t i=2; i<=n; i++)
	{
		fib = (fib_n1 + fib_n2)%10;
		fib_n2 = fib_n1;
		fib_n1 = fib;
		sum += (fib * fib) % 10;
		cout << i << endl;
	}
	
	return sum%10;
}

int main()
{
	int64_t num;
	
	cout<<sizeof(num)<<":"<<num<<endl;
	cin >> num;
	cout << last_dig_sqrsum_fib(num) << endl;
	
	return 0;
}