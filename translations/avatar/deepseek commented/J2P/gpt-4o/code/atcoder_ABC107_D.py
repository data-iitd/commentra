import sys
from bisect import bisect_right

class Task:
    def solve(self, arr):
        n = len(arr)
        sorted_arr = sorted(arr)  # Create a sorted copy of the array
        
        total = n * (n + 1) // 2  # Calculate the total number of elements
        l, r = 0, n - 1
        
        # Implement binary search to find the median
        while l < r:
            mid = l + (r - l) // 2
            target = sorted_arr[mid]
            cur = 0
            cnt = 0
            bit = [0] * (2 * n + 2)  # Initialize the binary indexed tree
            
            for x in range(n + 1, len(bit)):
                bit[x] += 1  # Initialize the binary indexed tree
            
            for i in range(n):
                cur += 1 if arr[i] <= target else -1
                for x in range(cur + n + 1, len(bit)):
                    bit[x] += 1  # Update the binary indexed tree
                for x in range(cur + n, 0, -1):
                    cnt += bit[x]  # Calculate the count of elements less than or equal to the target
            
            if cnt >= total // 2 + 1:
                r = mid  # Adjust the search range if the count is sufficient
            else:
                l = mid + 1
        
        return sorted_arr[l]  # Return the median value

def main():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])  # Read the size of the array
    arr = list(map(int, data[1:N + 1]))  # Read the array elements
    
    tsk = Task()
    print(tsk.solve(arr))  # Print the result of the solve method

if __name__ == "__main__":
    main()

# <END-OF-CODE>
