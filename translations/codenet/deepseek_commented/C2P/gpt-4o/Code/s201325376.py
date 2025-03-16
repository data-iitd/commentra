# Step 2: Declare the necessary variables.
a, b, c = map(int, input().split())

# Step 4: Initialize the count variable to zero.
count = 0

# Step 5: Start a for loop from a to b.
for i in range(a, b + 1):
    # Step 6: Check if c is divisible by i.
    if c % i == 0:
        # Step 7: Increment the count if the condition is true.
        count += 1

# Step 8: Print the count.
print(count)

# Step 9: Return 0 to indicate successful execution.
# In Python, we don't need to explicitly return 0.
# <END-OF-CODE>
