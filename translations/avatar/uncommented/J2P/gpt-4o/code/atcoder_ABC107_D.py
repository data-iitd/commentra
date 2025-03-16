import sys
from bisect import bisect_left, bisect_right

class Task:
    def solve(self, arr):
        n = len(arr)
        sorted_arr = sorted(arr)
        total = n * (n + 1) // 2
        l, r = 0, n - 1
        
        while l < r:
            mid = l + (r - l) // 2
            target = sorted_arr[mid]
            cur = 0
            cnt = 0
            bit = [0] * (2 * n + 2)
            
            for x in range(n + 1, len(bit)):
                bit[x] += 1
            
            for i in range(n):
                cur += 1 if arr[i] <= target else -1
                for x in range(cur + n + 1, len(bit)):
                    bit[x] += 1
                for x in range(cur + n, 0, -1):
                    cnt += bit[x]
            
            if cnt >= total // 2 + 1:
                r = mid
            else:
                l = mid + 1
        
        return sorted_arr[l]

def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    arr = list(map(int, data[1:N + 1]))
    tsk = Task()
    print(tsk.solve(arr))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
