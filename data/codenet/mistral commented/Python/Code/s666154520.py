# Take an integer input from the user and assign it to the variable 'n'
n = int(input())

# Iterate through numbers from 1 to 10^5 (1 to 9,999,999)
for i in range(1, 10 ** 5):
    # Check if the square of the current number 'i' is greater than the given number 'n'
    if i * i > n:
        # If the condition is true, then print the square of the previous number 'i-1' and exit the loop
        print((i-1) * (i-1))
        exit()
