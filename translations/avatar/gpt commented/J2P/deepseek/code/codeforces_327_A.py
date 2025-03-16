import sys

def main():
    # Read input from stdin
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    # Initialize max to the smallest possible integer value
    max_val = -sys.maxsize - 1
    
    # Iterate through all possible subarrays
    for i in range(n):
        for j in range(i, n):
            # Create a copy of the original array
            brr = arr[:]
            
            # Flip the values in the subarray from index i to j
            for k in range(i, j + 1):
                brr[k] = 1 - brr[k]
            
            # Count the number of 1's in the modified array
            count = brr.count(1)
            
            # Update max if the current count is greater
            max_val = max(max_val, count)
    
    # Handle the case when there is only one element in the array
    if n == 1:
        print(0 if arr[0] == 1 else 1)
    else:
        # Output the maximum count of 1's found
        print(max_val)

if __name__ == "__main__":
    main()
