import sys
from bisect import bisect_right

class Task:
    def solve(self, arr):
        n = len(arr)
        
        # Create a sorted copy of the input array
        sorted_arr = sorted(arr)
        
        # Calculate the total number of pairs possible in the array
        total = n * (n + 1) // 2
        
        # Initialize pointers for binary search
        l, r = 0, n - 1
        
        # Perform binary search to find the median-like value
        while l < r:
            mid = l + (r - l) // 2
            target = sorted_arr[mid]
            
            cur = 0
            cnt = 0
            
            # Create a Binary Indexed Tree (BIT) for counting
            bit = [0] * (2 * n + 2)
            
            # Initialize the BIT with base values
            for x in range(n + 1, len(bit)):
                bit[x] += 1
            
            # Count the number of elements less than or equal to the target
            for i in range(n):
                cur += 1 if arr[i] <= target else -1
                
                # Update the BIT with the current count
                x = cur + n + 1
                while x < len(bit):
                    bit[x] += 1
                    x += x & -x
                
                # Count the number of valid pairs using the BIT
                x = cur + n
                while x > 0:
                    cnt += bit[x]
                    x -= x & -x
            
            # Adjust the search range based on the count of pairs
            if cnt >= total // 2 + 1:
                r = mid  # Move left if count is sufficient
            else:
                l = mid + 1  # Move right if count is insufficient
        
        # Return the median-like value found
        return sorted_arr[l]

def main():
    # Read the number of elements in the array
    N = int(sys.stdin.readline().strip())
    
    # Populate the array with input integers
    arr = list(map(int, sys.stdin.readline().strip().split()))
    
    # Create an instance of the Task class to perform the calculation
    tsk = Task()
    
    # Solve the task and print the result
    print(tsk.solve(arr))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
