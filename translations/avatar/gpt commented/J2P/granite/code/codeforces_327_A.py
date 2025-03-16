
import sys

def main():
    # Read the size of the array
    n = int(input())
    # Initialize the array to hold n integers
    arr = list(map(int, input().split()))
    
    # Initialize max to the smallest possible integer value
    max = -sys.maxsize - 1
    
    # Iterate through all possible subarrays
    for i in range(n):
        for j in range(i, n):
            # Initialize a temporary variable to track the index for brr
            x = 0
            # Create a copy of the original array
            brr = arr[:]
            # Flip the values in the subarray from index i to j
            for k in range(i, j+1):
                if brr[k] == 0:
                    brr[k] = 1 # Change 0 to 1
                else:
                    brr[k] = 0 # Change 1 to 0
            # Count the number of 1's in the modified array
            count = checkNo(brr)
            # Update max if the current count is greater
            if count > max:
                max = count
    
    # Handle the case when there is only one element in the array
    if n == 1:
        if arr[0] == 1:
            print(0) # Output 0 if the single element is 1
        else:
            print(1) # Output 1 if the single element is 0
    else:
        # Output the maximum count of 1's found
        print(max)

# Method to count the number of 1's in the given array
def checkNo(brr):
    val = 0
    # Count each occurrence of 1 in the array
    for i in brr:
        if i == 1:
            val += 1
    return val # Return the total count of 1's

main() # Call the main function to execute the code

