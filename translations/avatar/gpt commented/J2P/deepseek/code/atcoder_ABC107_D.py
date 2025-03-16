import sys
import bisect

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
                bit[x] = 1

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
    # Read the number of elements in the array
    N = int(sys.stdin.readline().strip())
    
    # Read the input integers into an array
    arr = list(map(int, sys.stdin.readline().strip().split()))
    
    # Create an instance of the Task class to perform the calculation
    tsk = Task()
    
    # Solve the task and print the result
    print(tsk.solve(arr))

if __name__ == "__main__":
    main()
