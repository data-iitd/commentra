# Step 1: Import the sys module for input
import sys

# Step 2: Define the main function
def main():
    # Step 3: Read two integers from the user input
    a, b = map(int, sys.stdin.readline().split())
    
    # Step 4: Check if the product of 500 and a is greater than or equal to b
    if 500 * a >= b:
        print("Yes")  # Step 5: Print "Yes" if the condition is true
    else:
        print("No")   # Step 6: Print "No" if the condition is false

# Step 7: Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
