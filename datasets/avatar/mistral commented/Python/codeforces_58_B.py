# Ask the user to input an integer value
n = int(input())

# Initialize a variable i and set its value to n
for i in range(n, 0, -1):
    # Check if n is divisible by the current value of i
    if n % i == 0:
        # If the condition is true, update the value of n to i
        n = i
        # Print the current value of i
        print(i, end=' ')