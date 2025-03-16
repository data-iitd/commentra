
import sys

# Step 1: Import the Scanner class for input
from java.util import Scanner

# Step 2: Create a Scanner object to read input
sc = Scanner(sys.stdin)

# Step 3: Read the number of test cases
t = sc.nextInt()

# Step 4: Initialize a counter to keep track of the number of times the condition is met
count = 0

# Step 5: Use a while loop to iterate through each test case
while t > 0:
    # Step 6: Read the value of a for each test case
    a = sc.nextInt()
    # Step 6: Read the value of b for each test case
    b = sc.nextInt()
    # Step 6: Read the value of c for each test case
    c = sc.nextInt()

    # Step 7: Check if any of the values are 1 or if all three values are 1
    if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
        # Step 8: Increment the counter if the condition is met
        count += 1

    # Step 9: Decrement the number of test cases
    t -= 1

# Step 10: Print the counter value after the loop
print(count)

# 