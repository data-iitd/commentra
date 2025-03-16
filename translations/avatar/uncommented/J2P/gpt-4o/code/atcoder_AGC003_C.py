import sys
from collections import defaultdict
import heapq

def main():
    N = int(sys.stdin.readline().strip())
    map = {}
    nums = []
    
    for i in range(N):
        tmp = int(sys.stdin.readline().strip())
        heapq.heappush(nums, tmp)
        map[tmp] = i
    
    bin = 0
    diff = 0
    
    while nums:
        num = heapq.heappop(nums)
        idx = map[num]
        if (bin % 2) != (idx % 2):
            diff += 1
        bin += 1
        bin %= 2
    
    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
