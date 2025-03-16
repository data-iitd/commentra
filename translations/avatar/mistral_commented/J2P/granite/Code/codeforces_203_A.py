
import sys # Import the sys module

def solve(): # Define a function named solve
    x = int(input()) # Read the first integer x
    t = int(input()) # Read the second integer t
    a = int(input()) # Read the third integer a
    b = int(input()) # Read the fourth integer b
    da = int(input()) # Read the fifth integer da
    db = int(input()) # Read the sixth integer db

    first = 0 # Initialize first to zero
    second = 0 # Initialize second to zero
    ok = False # Initialize ok to false

    # Run a nested loop to find first and second
    for i in range(t):
        first = a - (da * i) # Calculate first for the current i
        for j in range(t):
            second = b - (db * j) # Calculate second for the current j

            # Check if second + first equals x or if either first or second equals x
            if second + first == x or second == x or first == x or x == 0:
                ok = True # Set ok to true if a match is found
                break # Exit the inner loop if a match is found

    # Print YES if ok is true, otherwise print NO
    if ok:
        print("YES")
    else:
        print("NO")

def main(): # Define a function named main
    solve() # Call the solve function

if __name__ == "__main__": # Check if the script is being run directly
    main() # Call the main function

