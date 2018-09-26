#Uses python3
import sys
import math

def distance(p1, p2):
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def brute_minimum_distance(pX):
    return min([distance(pX[i], pX[j]) for i in range(len(pX)) for j in range(i + 1, len(pX))])
    
def minimum_distance_merge(pY, min_value, max_value):
    min_dis = 2000000000
    
    pY_local = [pY[i] for i in range(len(pY)) if pY[i][0] <= max_value and pY[i][0] >= min_value]
    
    local_len = len(pY_local)
    
    for i in range(local_len):
        for j in range(1, 8):
            if((i + j) < local_len):
                min_dis = min(min_dis, distance(pY_local[i], pY_local[i + j]))
            if((i - j) >= 0):
                min_dis = min(min_dis, distance(pY_local[i], pY_local[i - j]))
    
    return min_dis

def minimum_distance(pX, pY, start, end):
    if(end - start <= 3):
        return brute_minimum_distance(pX[start:end])
    
    mid = int((start + end)/2)
    
    d1 = minimum_distance(pX, pY, start, mid)
    d2 = minimum_distance(pX, pY, mid, end)
    min_d1d2 = min(d1, d2)
    
    return min(min_d1d2, minimum_distance_merge(pY, pX[mid][0] - min_d1d2, pX[mid][0] + min_d1d2))

def minimum_distance_wrapper(points):
    pX = sorted(points, key=lambda point: point[0])
    pY = sorted(points, key=lambda point: point[1])
    return minimum_distance(pX, pY, 0, len(points))

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    
    points = list(zip(x, y))
    print("{0:.9f}".format(minimum_distance_wrapper(points)))
