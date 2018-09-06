// C++ program to find minimal 0 Fibonacci
// for a prime number p
#include<bits/stdc++.h>
using namespace std;
 
// Returns position of first Fibonacci number
// whose modulo p is 0.
int findMinZero(int p)
{
    int first = 1, second = 1, number = 2, next = 1;
    while (second!=1 || first!=0)
    {
		cout<<first<<" "<<second<<endl;
        next = (first + second) % p;
        first = second;
        second = next;
        number++;
    }
 
    return number - 1;
}
 
// Driver code
int main()
{
    int p = 0;
	
	cin >> p;
 
    cout << "Minimal zero is: "
         << findMinZero(p) << endl;
 
    return 0;
}