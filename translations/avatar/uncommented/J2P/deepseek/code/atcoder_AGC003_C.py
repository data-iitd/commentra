import sys
from collections import defaultdict, deque

def main():
    NUM = int(1e5 + 2)
    input = sys.stdin.readline
    N = int(input())
    nums = list(map(int, input().split()))
    map = defaultdict(int)
    pq = []
    
    for i in range(N):
        tmp = nums[i]
        pq.append(tmp)
        map[tmp] = i
    
    bin = 0
    diff = 0
    pq.sort()
    
    for num in pq:
        idx = map[num]
        if (bin % 2) != (idx % 2):
            diff += 1
        bin += 1
        bin %= 2
    
    ans = diff // 2
    print(ans)

if __name__ == "__main__":
    main()
