#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int32_t> optimal_sequence_dp(int32_t n) 
{
	std::vector<int32_t> sequence;
	std::vector<int32_t> MinimumSteps(n + 1, 2000000);
	MinimumSteps[1] = 0;
	MinimumSteps[0] = 0;
	int32_t steps = 0;
	
	for(int32_t i = 2; i <= n; ++i)
	{
		if(i % 2 == 0)
		{
			steps = MinimumSteps[int(i/2)] + 1;
			// std::cout << "2 " << steps << " :: " << i << " :: " << MinimumSteps[i] << std::endl;
			if(steps < MinimumSteps[i])
			{
				MinimumSteps[i] = steps;
			}
		}
		
		if(i % 3 == 0)
		{
			steps = MinimumSteps[int(i/3)] + 1;
			// std::cout << "3 " << steps  << " :: " << i << " :: " << MinimumSteps[i] << std::endl;
			if(steps < MinimumSteps[i])
			{
				MinimumSteps[i] = steps;
			}
		}
		
		steps = MinimumSteps[i-1] + 1;
		// std::cout << "1 " << steps  << " :: " << i << " :: " << MinimumSteps[i] << std::endl;
		if(steps < MinimumSteps[i])
		{
			MinimumSteps[i] = steps;
		}
	}
		
	return MinimumSteps;
}

vector<int32_t> optimal_sequence_dp_wrapper(int32_t n)
{
	vector<int32_t> optimals = optimal_sequence_dp(n);
	
	vector<int32_t> sequence;
	
	sequence.push_back(n);
	
	while(n > 1)
	{
		if((n % 3 == 0) && ((optimals[int(n/3)] + 1) == optimals[n]))
		{
			n = int(n/3);
			sequence.push_back(n);
		}
		else if((n % 2 == 0) && ((optimals[int(n/2)] + 1) == optimals[n]))
		{
			n = int(n/2);
			sequence.push_back(n);
		}
		else
		{
			n = n - 1;
			sequence.push_back(n);
		}
	}
	
	return sequence;
}


int32_t main() 
{
	int32_t n;
	std::cin >> n;
	vector<int32_t> sequence = optimal_sequence_dp_wrapper(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (int32_t i = sequence.size() - 1; i >= 0; --i) 
	{
 		std::cout << sequence[i] << " ";
	}
}
