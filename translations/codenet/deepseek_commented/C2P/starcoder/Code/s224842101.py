# Step 1: Include necessary headers
import sys

# Step 2: Define the main function
def main():
    # Step 3: Declare necessary variables
    i = 0
    a = 0
    b = 0
    s = 1
    count = [0, 0, 0, 0]

    # Step 4: Initialize the count array
    for i in range(4):
        count[i] = 0

    # Step 5: Read input values and update the count array
    for i in range(3):
        a, b = map(int, sys.stdin.readline().split())
        count[a-1] += 1
        count[b-1] += 1

    # Step 6: Calculate the product of the counts
    for i in range(4):
        s *= count[i]

    # Step 7: Check if the product is 4 and print the result
    if s == 4:
        print("YES")
    else:
        print("NO")

# Step 8: Call the main function
if __name__ == "__main__":
    main()

# 