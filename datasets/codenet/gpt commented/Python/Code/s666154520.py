# Read an integer input from the user
n = int(input())

# Iterate over a range of numbers from 1 to 100,000
for i in range(1, 10 ** 5):
    # Check if the square of the current number exceeds the input number n
    if i * i > n:
        # If it does, print the square of the previous number (i-1)
        print((i-1) * (i-1))
        # Exit the program after printing the result
        exit()
