#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <functional>
#include <cstdlib>
#include <ctime>

using std::vector;

struct Segment 
{
	int64_t start, end;
};

vector<int64_t> optimal_points(vector<Segment> &segments) 
{
	vector<int64_t> points;
	int i = 0;	
	int64_t current_last = 0;
	
	std::sort(segments.begin(), segments.end(), 
			  [](auto const &a, auto const &b) -> bool {return (a.end <= b.end);});
	
	/*
	std::cout << "Sorted Segments:\n";
	
	for (size_t i = 0; i < segments.size(); ++i) 
	{
		std::cout << i << " " << segments[i].start << " " << segments[i].end << "\n";
	}
	*/
	
	while(i < segments.size())
	{		
		current_last = segments[i].end;
		points.push_back(current_last);
		i+=1;
		
		while(i < segments.size() && segments[i].start <= current_last)
		{
			i+=1;
		}
	}
	
	return points;
}

int main() 
{
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
  
	for (size_t i = 0; i < segments.size(); ++i) 
	{
		std::cin >> segments[i].start >> segments[i].end;
	}
  
	vector<int64_t> points = optimal_points(segments);
	std::cout << points.size() << "\n";
  
	for (size_t i = 0; i < points.size(); ++i) 
	{
		std::cout << points[i] << " ";
	}
}

/*
void stress_test(vector<Segment> segments, vector<int> points)
{
	int range = 1000;
  
	for (size_t i = 0; i < segments.size(); ++i) 
	{
		segments[i].start = (std::rand() % range) + 1;
		segments[i].end = segments[i].start + (std::rand() % range) + 1;
	}
	
	int flag = 0;
	
	for (size_t i = 0; i < segments.size(); ++i) 
	{
		for(size_t j = 0; j < points.size(); ++j)
		{
			if(segments[i].start <= points[j] && segments[i].end >= points[j])
				flag = 1;
		}
		if(flag == 0)
			break;
	}
	
	if(flag == 0)
	{
		std::cout << "Incorrect Answer:\nSegments:\n";
		for (size_t i = 0; i < segments.size(); ++i) 
		{
			std::cout<< i << " " << segments[i].start << " " << segments[i].end << "\n"; 
		}	
	
		for (size_t i = 0; i < segments.size(); ++i) 
		{
			std::cout<< points[i] << " "; 
		}
	}
}

int main()
{
	for(size_t i=0; i<10000; i++)
	{
		int n = (std::rand() % 100) + 1;
	
		vector<Segment> segments(n);
	
		vector<int> points = optimal_points(segments);
		
		stress_test(segments, points);
	}
	
	return 0;
}
*/