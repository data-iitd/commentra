# Step 1: Import the sys module for input
import sys

def main():
    # Step 4: Read the number of test cases
    t = int(sys.stdin.readline().strip())
    count = 0  # Step 6: Initialize a counter to keep track of the number of times the condition is met

    # Step 7: Use a while loop to iterate through each test case
    while t > 0:
        t -= 1
        # Step 8: Read the values of a, b, and c for each test case
        a, b, c = map(int, sys.stdin.readline().strip().split())

        # Step 9: Check if any of the values are 1 or if all three values are 1
        if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
            count += 1  # Step 10: Increment the counter if the condition is met

    # Step 11: Print the counter value after the loop
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
