
import sys
import heapq

class Main:
    def main(self):
        N = int(sys.stdin.readline())
        nums = []
        for i in range(N):
            num = int(sys.stdin.readline())
            nums.append(num)
        heapq.heapify(nums)
        bin = 0
        diff = 0
        while len(nums) > 0:
            num = heapq.heappop(nums)
            idx = nums.index(num)
            if (bin % 2)!= (idx % 2):
                diff += 1
            bin += 1
            bin %= 2
        ans = diff // 2
        print(ans)

if __name__ == "__main__":
    obj = Main()
    obj.main()

