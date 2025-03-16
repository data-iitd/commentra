
import sys

def main():
    # Read four integer inputs from the user
    x = int(input()) # First integer
    y = int(input()) # Second integer
    a = int(input()) # Lower bound of the range
    b = int(input()) # Upper bound of the range
    
    # Initialize variables for calculations
    j = 2
    i = 0
    x1 = 0
    y1 = 0
    c = 0
    ans = True # Flag to check if a valid solution exists
    
    # Determine the maximum of x and y
    c = max(x, y)
    
    # Check if the maximum value exceeds the upper bound b
    if c > b:
        print(0) # Output 0 if no valid multiples exist
        ans = False # Set answer flag to false
    
    # Loop to find the least common multiple (LCM) of x and y
    while c % min(x, y)!= 0 and ans:
        # Multiply by j to find the next multiple
        if x > y:
            c = x * j # Calculate next multiple of x
            j += 1
        else:
            c = y * j # Calculate next multiple of y
            j += 1
        
        # Check if the calculated multiple exceeds the upper bound b
        if c > b:
            print(0) # Output 0 if no valid multiples exist
            ans = False # Set answer flag to false
            break # Exit the loop
    
    # If a valid multiple was found within the bounds
    if ans:
        count = 0 # Initialize count of valid multiples
        # Find the first multiple of c within the range [a, b]
        for i in range(a, b + 1):
            if i % c == 0: break # Break when a multiple is found
        
        # Check if a valid multiple was found within the range
        if i!= b + 1:
            # Calculate the number of multiples of c in the range [a, b]
            print(((b - i) // c) + 1)
        else:
            print(0) # Output 0 if no multiples found

if __name__ == "__main__":
    main()

