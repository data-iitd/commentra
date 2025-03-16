
# Step 1: Import necessary libraries
import sys

# Step 2: Define the main function
def main():
    # Step 3: Declare variables to store input values
    a, b, c, d, e, k = map(int, input().split())

    # Step 4: Read input values from the user
    # Step 5: Calculate the difference between e and a and check if it is less than or equal to k
    if e - a <= k:
        print("Yay!")
    else:
        print(":(")

# Step 6: Call the main function
if __name__ == "__main__":
    main()

# Step 7: Return 0 to indicate successful execution
sys.exit(0)

