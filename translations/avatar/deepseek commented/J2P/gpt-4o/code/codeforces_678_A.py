# Step 1: Import the sys module for reading input.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Read an integer value from the user and store it in the variable n.
    n = int(input())
    # Step 4: Read another integer value from the user and store it in the variable k.
    k = int(input())
    
    # Step 5: Increment the value of n by 1.
    n += 1
    
    # Step 6: Initialize a variable z to 0.
    z = 0
    
    # Step 7: Check if n is not divisible by k.
    if n % k != 0:
        # If true, calculate the difference between k and the remainder of n divided by k, and store it in z.
        z = k - n % k
    
    # Step 8: Print the new value of n plus the value of z.
    print(n + z)

# Step 9: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
