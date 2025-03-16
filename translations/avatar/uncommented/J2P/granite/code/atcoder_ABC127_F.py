
import sys
import heapq

def main():
    t = int(input())
    s = []
    min_heap = []
    max_heap = []
    sum_min = 0
    sum_max = 0
    sum_b = 0
    min_val = 0
    for _ in range(t):
        s = input().split()
        if s[0] == '1':
            in_val = int(s[1])
            b = int(s[2])
            sum_b += b
            if in_val > min_val:
                heapq.heappush(max_heap, -in_val)
                sum_max -= in_val
            else:
                heapq.heappush(min_heap, in_val)
                sum_min += in_val
            if len(max_heap) > len(min_heap) + 1:
                val = -heapq.heappop(max_heap)
                sum_max += val
                sum_min -= val
                heapq.heappush(min_heap, val)
            elif len(min_heap) > len(max_heap):
                val = heapq.heappop(min_heap)
                sum_max -= val
                sum_min += val
                heapq.heappush(max_heap, -val)
            min_val = min_heap[0]
        else:
            ans = min_val * len(min_heap) - sum_min
            ans1 = min_val * len(max_heap) + sum_max
            print(min_val, ans + ans1 + sum_b)

if __name__ == "__main__":
    main()
