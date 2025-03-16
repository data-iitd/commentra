# Step 3: Declare an integer variable n
n = int(input())  # Step 4: Read an integer input from the user and store it in n
m = n  # Step 5: Copy the value of n to m
n -= 1  # Step 6: Decrement the value of n by 1
while n > 1:  # Step 7: Start a while loop that runs while n is greater than 1
    m *= n  # Inside the loop, multiply m by n
    n -= 1  # Decrement n by 1
print(m)  # Step 8: Print the value of m, which represents the factorial of the input number
# Step 9: Return 0 to indicate successful execution (not needed in Python)
# <END-OF-CODE>
