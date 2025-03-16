

import sys
from heapq import *

def main():
    t = int(input())
    for _ in range(t):
        s = input().split()
        if s[0] == '2':
            ans = heappop(min_heap)
            ans *= len(min_heap)
            ans -= sum(min_heap)
            ans1 = heappop(max_heap)
            ans1 = sum(max_heap) - ans1
            print(ans + ans1 + sum_b)
        else:
            in_ = int(s[1])
            sum_b += int(s[2])
            if in_ > min_heap[0]:
                heappush(max_heap, -heappush(min_heap, -in_))
            else:
                heappush(min_heap, in_)
            if len(min_heap) > len(max_heap) + 1:
                heappush(max_heap, -heappop(min_heap))
            elif len(max_heap) > len(min_heap):
                heappush(min_heap, -heappop(max_heap))

if __name__ == '__main__':
    input = sys.stdin.readline
    min_heap, max_heap = [], []
    sum_b = 0
    main()

