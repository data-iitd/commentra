import sys
import bisect

def solve(arr):
    # Get the length of the input array
    n = len(arr)
    
    # Create a sorted copy of the input array
    sorted = arr[:]
    sorted.sort()
    
    # Calculate the total number of pairs possible in the array
    total = n * (n + 1) // 2
    
    # Initialize pointers for binary search
    l = 0
    r = n - 1
    
    # Perform binary search to find the median-like value
    while l < r:
        # Calculate the midpoint of the current search range
        mid = l + (r - l) // 2
        
        # Get the target value from the sorted array
        target = sorted[mid]
        
        # Initialize counters for the current state
        cur = 0
        cnt = 0
        
        # Create a Binary Indexed Tree (BIT) for counting
        bit = [0] * (2 * n + 2)
        
        # Initialize the BIT with base values
        for x in range(n + 1, len(bit)):
            bit[x] += 1
        
        # Count the number of elements less than or equal to the target
        for i in range(n):
            cur += arr[i] <= target
            
            # Update the BIT with the current count
            for x in range(cur + n + 1, len(bit), 1):
                bit[x] += 1
            
            # Count the number of valid pairs using the BIT
            for x in range(cur + n, 0, -1):
                cnt += bit[x]
        
        # Adjust the search range based on the count of pairs
        if cnt >= total // 2 + 1:
            r = mid
        else:
            l = mid + 1
    
    # Return the median-like value found
    return sorted[l]

if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(sys.stdin.readline())
    
    # Initialize an array to hold the input integers
    arr = list(map(int, sys.stdin.readline().split()))
    
    # Solve the task and print the result
    print(solve(arr))

