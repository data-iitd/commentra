

t = int(input()) # Step 1: Read the number of test cases
count = 0 # Step 6: Initialize a counter to keep track of the number of times the condition is met

# Step 7: Use a while loop to iterate through each test case
while t > 0:
    a, b, c = map(int, input().split()) # Step 8: Read the values of a, b, and c for each test case

    # Step 9: Check if any of the values are 1 or if all three values are 1
    if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
        count += 1 # Step 10: Increment the counter if the condition is met
    t -= 1 # Step 12: Decrement the test case counter

# Step 11: Print the counter value after the loop
print(count) # 