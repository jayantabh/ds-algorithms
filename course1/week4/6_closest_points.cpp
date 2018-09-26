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

double brute_minimum_distance(vector<pair<int32_t, int32_t>> &xP, 
							  int32_t start, int32_t end)
{
	double minimum_distance = 2.0E9;
	
	for(int32_t i = start; i < end; ++i)
	{
		for(int32_t j = i + 1; j < end; ++j)
		{
			if(i != j)
			{
				minimum_distance = std::min(minimum_distance, distance(xP[i], xP[j]));
			}
		}
	}
	
	return minimum_distance;
}

double minimal_distance_merge(vector<pair<int32_t, int32_t>> yP, 
							  int32_t start_value, int32_t end_value)
{
	double minimum_distance = 2.0E9, current_distance = 0.0;
	
	int32_t j;
	
	vector<pair<int32_t, int32_t>> yPL;
	
	std::copy_if(std::begin(yP), std::end(yP), std::back_inserter(yPL), 
				 [&start_value, &end_value](const pair<int32_t, int32_t>& p)
				 { 
					return p.first <= end_value && p.first >= start_value;
				 });
	
	// for(int32_t i = 0; i < yP.size(); ++i)
	// {
		// if(yP[i].first >= start_value && yP[i].first <= end_value)
		// {
			// yPL.push_back(yP[i]);
		// }
	// }
	
	for(int32_t i = 0; i < yPL.size(); ++i)
	{
		j = 1;
		while(j < 8)
		{
			if(i + j < yPL.size())
			{
				minimum_distance = std::min(minimum_distance, distance(yPL[i], yPL[i + j]));
			}
			
			if(i - j >= 0)
			{
				minimum_distance = std::min(minimum_distance, distance(yPL[i], yPL[i - j]));
			}
			
			++j;
		}
	}
	
	return minimum_distance;
}

double minimal_distance(vector<pair<int32_t, int32_t>> &xP, 
                        vector<pair<int32_t, int32_t>> &yP, 
						int32_t start, int32_t end) 
{
	double d1 = 0.0, d2 = 0.0, min_d1d2 = 0.0, minimum_distance = 0.0;
	int32_t mid = int((start + end)/2);
	int32_t d3_start = mid, d3_end = mid;
	
	if((end - start) <= 3)
	{
		return brute_minimum_distance(xP, start, end);
	}
	
	d1 = minimal_distance(xP, yP, start, mid);
	d2 = minimal_distance(xP, yP, mid, end);
	
	min_d1d2 = std::min(d1, d2);
	
	return std::min(min_d1d2, minimal_distance_merge(yP, int32_t(xP[mid].first - min_d1d2), 
										   int32_t(xP[mid].first + min_d1d2) + 1));
}

double minimal_distance_wrapper(vector<pair<int32_t, int32_t>> &points)
{
	vector<pair<int32_t, int32_t>> xP, yP;
	
	std::sort(points.begin(), points.end(), compare_x);
	
	xP = points;
	
	std::sort(points.begin(), points.end(), compare_y);
	
	yP = points;
	
	return minimal_distance(xP, yP, 0, points.size());
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
