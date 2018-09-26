#include <iostream> 
#include <limits>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std; 

struct Point32_t 
{ 
    int32_t x, y; 
}; 

int32_t compareX(const void* a, const void* b) 
{ 
    Point32_t *p1 = (Point32_t *)a,  *p2 = (Point32_t *)b; 
    return (p1->x - p2->x); 
} 
 
int32_t compareY(const void* a, const void* b) 
{ 
    Point32_t *p1 = (Point32_t *)a,   *p2 = (Point32_t *)b; 
    return (p1->y - p2->y); 
} 
  
double dist(Point32_t p1, Point32_t p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                 (p1.y - p2.y)*(p1.y - p2.y) 
               ); 
} 

double bruteForce(Point32_t P[], int32_t n) 
{ 
    double min = std::numeric_limits<double>::max(); 
    for (int32_t i = 0; i < n; ++i) 
        for (int32_t j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
                min = dist(P[i], P[j]); 
    return min; 
} 

double min(double x, double y) 
{ 
    return (x < y)? x : y; 
} 

double stripClosest(Point32_t strip[], int32_t size, double d) 
{ 
    double min = d;  

    for (int32_t i = 0; i < size; ++i) 
        for (int32_t j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
  
    return min; 
} 

double closestUtil(Point32_t Px[], Point32_t Py[], int32_t n) 
{ 
    if (n <= 3) 
        return bruteForce(Px, n); 
 
    int32_t mid = n/2; 
    Point32_t midPoint32_t = Px[mid]; 

    Point32_t Pyl[mid+1];   
    Point32_t Pyr[n-mid-1];  
    int32_t li = 0, ri = 0;  
    for (int32_t i = 0; i < n; i++) 
    { 
      if (Py[i].x <= midPoint32_t.x) 
         Pyl[li++] = Py[i]; 
      else
         Pyr[ri++] = Py[i]; 
    } 

	double dl = closestUtil(Px, Pyl, mid); 
    double dr = closestUtil(Px + mid, Pyr, n-mid); 

    double d = min(dl, dr); 

    Point32_t strip[n]; 
    int32_t j = 0; 
    for (int32_t i = 0; i < n; i++) 
        if (abs(Py[i].x - midPoint32_t.x) < d) 
            strip[j] = Py[i], j++; 

    return min(d, stripClosest(strip, j, d) ); 
} 
double closest(Point32_t P[], int32_t n) 
{ 
    Point32_t Px[n]; 
    Point32_t Py[n]; 
    for (int32_t i = 0; i < n; i++) 
    { 
        Px[i] = P[i]; 
        Py[i] = P[i]; 
    } 
  
    qsort(Px, n, sizeof(Point32_t), compareX); 
    qsort(Py, n, sizeof(Point32_t), compareY); 
  
    return closestUtil(Px, Py, n); 
} 

int main() 
{
	size_t n;
	std::cin >> n;
	Point32_t P[n];
	
	for (size_t i = 0; i < n; i++) 
	{
		std::cin >> P[i].x >> P[i].y;
	}
	
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << closest(P, n) << "\n";
}