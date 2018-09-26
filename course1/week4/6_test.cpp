#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;

bool compare_x(const pair<int32_t, int32_t> &a, const pair<int32_t, int32_t> &b)
{
	if(a.first > b.first)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool compare_y(const pair<int32_t, int32_t> &a, const pair<int32_t, int32_t> &b)
{
	if(a.second > b.second)
	{
		return false;
	}
	else
	{
		return true;
	}
}

double distance(pair<int32_t, int32_t> a, pair<int32_t, int32_t> b)
{
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

double minimal_distance_merge(vector<pair<int32_t, int32_t>> points, int start, int end)
{
	double minimum_distance = 2.0E9, current_distance = 0.0;
	
	int j;
	
	vector<pair<int32_t, int32_t>> local_points;
	
	for(size_t i = start; i < end; ++i)
	{
		local_points.push_back(points[i]);
	}
	
	std::sort(local_points.begin(), local_points.end(), compare_y);
	
	for(int i = 0; i < end - start; ++i)
	{
		j = 1;
		while(j < 8)
		{
			if(i + j < end - start)
			{
				current_distance = distance(local_points[i], local_points[i + j]);
				// std::cout << "i + j: " << i << " " << j << " " 
						  // << local_points[i].first 
						  // << " " << local_points[i].second << std::endl;
				// std::cout << local_points[j].first << " " 
						  // << local_points[j].second << " " 
						  // << current_distance << std::endl;
				if(current_distance < minimum_distance)
				{
					minimum_distance = current_distance;
				}
			}
			
			if(i - j >= 0)
			{
				current_distance = distance(local_points[i], local_points[i - j]);
				// std::cout << "i - j: " << i << " " << j << " " 
						  // << local_points[i].first 
						  // << " " << local_points[i].second << std::endl;
				// std::cout << local_points[j].first << " " 
						  // << local_points[j].second << " " 
						  // << current_distance << std::endl;
				if(current_distance < minimum_distance)
				{
					minimum_distance = current_distance;
				}
			}
			
			++j;
		}
	}
	
	return minimum_distance;
}

int main() 
{
	size_t n;
	std::cin >> n;
	vector<pair<int32_t, int32_t>> points(n);
	
	for (size_t i = 0; i < n; i++) 
	{
		std::cin >> points[i].first >> points[i].second;
	}
	
	// std::cout << "Distance: (3, 1) (3, 3): " << distance(std::make_pair(int32_t(3),int32_t(1)), std::make_pair(int32_t(3),int32_t(3)));  
	// std::cout << "Distance: (2, 2) (4, 4): " << distance(std::make_pair(int32_t(2),int32_t(2)), std::make_pair(int32_t(4),int32_t(4)));
	
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimal_distance_merge(points, 0, points.size()) << "\n";
}
