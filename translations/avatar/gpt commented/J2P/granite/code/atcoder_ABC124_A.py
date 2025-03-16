
a, b = map(int, input().split()) # Reading two integers from the user

sum = 0 # Initializing a variable to hold the sum of selected integers

for i in range(2): # Loop to iterate twice to calculate the sum
    if a >= b:
        sum += a # Add 'a' to the sum
        a -= 1 # Decrement 'a' by 1
    else:
        sum += b # Add 'b' to the sum
        b -= 1 # Decrement 'b' by 1

print(sum) # Output the final sum to the console

