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
	return a.first <= b.first;
}

bool compare_y(const pair<int32_t, int32_t> &a, const pair<int32_t, int32_t> &b)
{
	return a.second <= b.second;
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
	
	std::copy(points.begin() + start, points.begin() + end, std::back_inserter(local_points));
	
	// for(size_t i = start; i < end; ++i)
	// {
		// local_points.push_back(points[i]);
	// }
	
	std::sort(local_points.begin(), local_points.end(), compare_y);
	
	for(int i = 0; i < end - start; ++i)
	{
		j = 1;
		while(j < 8)
		{
			if(i + j < end - start)
			{
				minimum_distance = std::min(minimum_distance, distance(local_points[i], local_points[i + j]));
			}
			
			if(i - j >= 0)
			{
				minimum_distance = std::min(minimum_distance, distance(local_points[i], local_points[i - j]));
			}
			
			++j;
		}
	}
	
	return minimum_distance;
}

double minimal_distance(vector<pair<int32_t, int32_t>> &points, int start, int end) 
{
	double d1 = 0.0, d2 = 0.0, min_d1d2 = 0.0, minimum_distance = 0.0;
	int mid = int((start + end)/2);
	int d3_start = mid, d3_end = mid;
	
	if((end - start) == 3)
	{
		return std::min(std::min(distance(points[start], points[start + 1]), 
								 distance(points[start + 1], points[end - 1])), 
								 distance(points[start], points[end - 1]));
	}
	else if((end - start) == 2)
	{
		return distance(points[start], points[end - 1]);
	}
	
	d1 = minimal_distance(points, start, mid);
	d2 = minimal_distance(points, mid, end);
	
	min_d1d2 = std::min(d1, d2);
	
	for(int j = mid; j >= start; --j)
	{
		if(double(points[j].first) < (points[mid].first - min_d1d2))
		{
			d3_start = j + 1;
			break;
		}
		else if(j == start)
		{
			d3_start = start;
		}
	}
		
	for(int j = mid; j < end; ++j)
	{
		if(double(points[j].first) > (points[mid].first + min_d1d2))
		{
			d3_end = j;
			break;
		}
		else if(j == end - 1)
		{
			d3_end = end - 1;
		}
	}
	
	return std::min(min_d1d2, minimal_distance_merge(points, d3_start, d3_end));
}

double minimal_distance_wrapper(vector<pair<int32_t, int32_t>> &points)
{
	std::sort(points.begin(), points.end(), compare_x);
	
	return minimal_distance(points, 0, points.size());
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
	
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimal_distance_wrapper(points) << "\n";
}
