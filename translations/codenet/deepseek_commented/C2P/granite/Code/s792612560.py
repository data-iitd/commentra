
n = int(input()) # Step 3: Declare an integer variable n
m = n # Step 3: Declare an unsigned long long integer variable m
n -= 1 # Step 4: Read an integer input from the user and store it in n
for n in range(n, 1, -1): # Step 7: Start a for loop that runs while n is greater than 1
    m *= n # Inside the loop, multiply m by n and decrement n by 1
print(m) # Step 8: Print the value of m, which represents the factorial of the input number
