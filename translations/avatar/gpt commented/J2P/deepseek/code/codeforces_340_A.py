import sys

def main():
    # Read four long integer inputs from the user
    x = int(input())  # First integer
    y = int(input())  # Second integer
    a = int(input())  # Lower bound of the range
    b = int(input())  # Upper bound of the range
    
    # Initialize variables for calculations
    j = 2
    ans = True
    
    # Determine the maximum of x and y
    c = max(x, y)
    
    # Check if the maximum value exceeds the upper bound b
    if c > b:
        print("0")  # Output 0 if no valid multiples exist
        ans = False
    
    # Loop to find the least common multiple (LCM) of x and y
    while c % min(x, y) != 0 and ans:
        # Multiply by j to find the next multiple
        if x > y:
            c = x * j
            j += 1
        else:
            c = y * j
            j += 1
        
        # Check if the calculated multiple exceeds the upper bound b
        if c > b:
            print("0")  # Output 0 if no valid multiples exist
            ans = False
            break
    
    # If a valid multiple was found within the bounds
    if ans:
        # Find the first multiple of c within the range [a, b]
        for i in range(a, b + 1):
            if i % c == 0:
                break
        
        # Check if a valid multiple was found within the range
        if i != b + 1:
            # Calculate the number of multiples of c in the range [a, b]
            print(((b - i) // c) + 1)
        else:
            print("0")  # Output 0 if no multiples found

if __name__ == "__main__":
    main()
