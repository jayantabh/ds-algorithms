#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment 
{
	int32_t start, end;
};

/*
struct 
{
    bool operator()(vector<Segment> &a, vector<Segment> &b) const
    {   
        if(a.start < b.start)
		{	
			return true;
		}
		else if(a.start == b.start)
		{
			if(a.end < b.end)
				return true;
			else
				return false;
		}
		else
		{	
			return false;
		}
    }   
}customLess;
*/

vector<int32_t> optimal_points(vector<Segment> &segments) 
{
	vector<int32_t> points;
	int i = 0,
		current_last = 0;
	
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
		//points.push_back(segments[i].start);
		
		current_last = segments[i].end;
		
		points.push_back(current_last);
		
		i += 1;
		
		while(segments[i].start <= current_last)
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
  
	vector<int> points = optimal_points(segments);
  
	std::cout << points.size() << "\n";
  
	for (size_t i = 0; i < points.size(); ++i) 
	{
		std::cout << points[i] << " ";
	}
}