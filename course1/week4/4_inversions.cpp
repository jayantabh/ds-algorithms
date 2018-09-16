#include <iostream>
#include <vector>

using std::vector;

int64_t get_number_of_inversions(vector<int64_t> &a, vector<int64_t> &b, size_t left, size_t right) 
{
	int64_t number_of_inversions = 0;
	
	if (right <= left + 1) return number_of_inversions;
	
	size_t ave = int64_t((right + left) / 2);
	
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	
	// std::cout << "Dimensions: " << left << " " << ave << " " << right << std::endl;
	
	size_t k = left, i = left, j = ave;
	
	while(i < ave && j < right)
	{
		if(a[i] > a[j])
		{
			number_of_inversions += ave - i;
			b[k++] = a[j++];
		}
		else
		{
			b[k++] = a[i++];
		}
	}
	
	// std::cout << "Dimensions Repeat: " << i << " " << j << std::endl;
	
	while(i < ave)
	{
		// std::cout << "1st\n";
		b[k++] = a[i++];
	}
	
	// std::cout << "Mid\n";
	
	while(j < right)
	{
		b[k++] = a[j++];
	}
	
	
	// for(size_t i = left; i < right; i++)
	// {
		// std::cout << a[i] << " ";
	// }
	
	// std::cout << std::endl;
	
	for(size_t i = left; i < right; i++)
	{
		a[i] = b[i];
		// std::cout << a[i] << " ";
	}
	
	// std::cout << std::endl;
	
	// for(size_t i = left; i < right; i++)
	// {
		// std::cout << b[i] << " ";
	// }
	
	// std::cout << std::endl << "Number of Inversions: " << number_of_inversions << std::endl;
	
	return number_of_inversions;
}

int main() 
{
	int64_t n;
	std::cin >> n;
	vector<int64_t> a(n);
	
	for (size_t i = 0; i < a.size(); i++) 
	{
		std::cin >> a[i];
	}
	
	vector<int64_t> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
