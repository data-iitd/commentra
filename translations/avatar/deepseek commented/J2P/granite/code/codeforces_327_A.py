
import sys

def main():
    n = int(input()) # Reading the size of the array
    arr = list(map(int, input().split())) # Reading the elements of the array
    
    max_count = -sys.maxsize # Initializing max_count to the minimum possible integer value
    
    for i in range(n): # Iterating over all possible starting points of subarrays
        for j in range(i, n): # Iterating over all possible ending points of subarrays
            brr = arr[:] # Copying the elements of arr to brr
            for k in range(i, j+1): # Flipping the elements in the current subarray
                if brr[k] == 0:
                    brr[k] = 1
                else:
                    brr[k] = 0
            count = check_no(brr) # Counting the number of 1s in the modified subarray
            
            if count > max_count:
                max_count = count # Updating max_count if the current count is greater
    
    if n == 1: # Handling the special case of a single element array
        if arr[0] == 1:
            print(0)
        else:
            print(1)
    else:
        print(max_count) # Printing the maximum count of 1s found

def check_no(brr): # Helper method to count the number of 1s in an array
    return sum(1 for i in brr if i == 1)

if __name__ == "__main__":
    main()

