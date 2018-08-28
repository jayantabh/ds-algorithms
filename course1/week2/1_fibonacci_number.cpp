#include <iostream>
#include <cstdlib>
using namespace std;

//Recursion with cache for already computed values
int fibonacci(int n)
{
	int fib[n+1];
	fib[0] = 0;
	fib[1] = 1;
	
	if(n==1 || n==0)
		return fib[n];
	
	for(int i=2; i<=n; i++)
		fib[i] = fib[i-1] + fib[i-2];
	
	return fib[n];
}

/*
// Naive Implementation to check answer for stress test
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}
*/

/*
//Stress test to check validity
int stress_test()
{
	int n = rand()%45 + 2;
	if(fibonacci_naive(n) != fibonacci(n))
	{
		cout << "Wrong Answer: " << n << endl;
 		return 1;
	}
	else
		cout << "Success: " << n << endl;
		return 0;
}
*/

int main()
{
	int n;

	std::cin >> n;
	std::cout << fibonacci(n) << std::endl;
	
	return 0;
}

/*
//Main for stress test
int main()
{
	while(true)
	{
		if(stress_test() == 1)
			break;
	}
			
	return 0;
}
*/