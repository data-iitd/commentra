
import sys
import heapq

def main():
    N = int(input())
    nums = []
    for i in range(N):
        num = int(input())
        heapq.heappush(nums, num)
    bin = 0
    diff = 0
    while nums:
        num = heapq.heappop(nums)
        idx = nums.index(num)
        if (bin % 2)!= (idx % 2):
            diff += 1
        bin += 1
        bin %= 2
    ans = diff // 2
    print(ans)

if __name__ == '__main__':
    main()

