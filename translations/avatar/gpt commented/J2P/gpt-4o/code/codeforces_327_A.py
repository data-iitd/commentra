def main():
    # Read the size of the array
    n = int(input())
    # Initialize the array to hold n integers
    arr = list(map(int, input().split()))
    
    # Initialize max to the smallest possible integer value
    max_count = float('-inf')
    
    # Iterate through all possible subarrays
    for i in range(n):
        for j in range(i, n):
            # Create a copy of the original array
            brr = arr[:]
            
            # Flip the values in the subarray from index i to j
            for k in range(i, j + 1):
                brr[k] = 1 - brr[k]  # Change 0 to 1 and 1 to 0
            
            # Count the number of 1's in the modified array
            count = brr.count(1)
            
            # Update max if the current count is greater
            if count > max_count:
                max_count = count
    
    # Handle the case when there is only one element in the array
    if n == 1:
        if arr[0] == 1:
            print(0)  # Output 0 if the single element is 1
        else:
            print(1)  # Output 1 if the single element is 0
    else:
        # Output the maximum count of 1's found
        print(max_count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
