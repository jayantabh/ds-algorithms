# Uses python3
import sys

def binary_search_ends(ends, left, right, x):
	mid = int((left + right)/2)
	
	if(left + 1 >= right):
		if(ends[mid] < x):
			return mid
		else:
			return mid - 1
	
	if(ends[mid] >= x):
		return binary_search_ends(ends, left, mid, x)
	else:
		return binary_search_ends(ends, mid + 1, right, x)

def binary_search_end_wrapper(ends, x):
	return binary_search_ends(ends, 0, len(ends), x) + 1
	
def binary_search_start(starts, left, right, x):
	mid = int((left + right)/2)
	
	print(starts, ' :: ', x, ' :: ', left, ' :: ', right, ' :: ', mid)
	
	if((left + 1) >= right):
		if(starts[mid] > x):
			return mid
		else:
			return mid + 1

	if(starts[mid] > x):
		return binary_search_start(starts, left, mid, x)
	else:
		return binary_search_start(starts, mid + 1, right, x)

def binary_search_start_wrapper(starts, x):
	return len(starts) - binary_search_start(starts, 0, len(starts), x)

def fast_count_segments(starts, ends, points):
	cnt = [0] * len(points)
	
	start_greater = 0 
	end_smaller = 0
	
	starts.sort();
	ends.sort();
	
	print(starts, ' :: ', ends)
	
	for p in range(len(points)):
		start_greater = binary_search_start_wrapper(starts, points[p])
		end_smaller = binary_search_end_wrapper(ends, points[p])
		cnt[p] = (len(starts) - start_greater - end_smaller)
		
	return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
