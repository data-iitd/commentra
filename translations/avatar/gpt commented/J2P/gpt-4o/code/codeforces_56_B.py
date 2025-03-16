# Import necessary modules
import sys

def main():
    # Read the length of the array
    len_a = int(input())
    
    # Initialize an array of the specified length
    a = list(map(int, input().split()))
    
    # Initialize variables to track the left and right indices of the mismatch
    l = 0
    r = 0
    
    # Flags to indicate the state of the search for mismatches
    flag = False
    isTrue = False
    
    # Loop through the array to find the first and second mismatches
    for i in range(len_a):
        # Check if the current element does not match its expected value
        if a[i] != i + 1 and not flag:
            # Set the left index to the current position (1-based index)
            l = i + 1
            # Set the flag to indicate the first mismatch has been found
            flag = True
            continue
        
        # Check for the second mismatch
        if a[i] != i + 1 and flag:
            # Set the right index to the current position (1-based index)
            r = i + 1
            # Check if the previous element is less than the current element
            if (a[r - 1] - a[r - 2] > 0):
                # Set the isTrue flag to indicate a valid mismatch has been found
                isTrue = True
                break
    
    # Output the result based on whether a valid mismatch was found
    print(f"{l} {r}" if not isTrue else "0 0")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
