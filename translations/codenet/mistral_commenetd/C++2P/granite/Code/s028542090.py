

k = int(input()) # Read the number of input numbers from the standard input
a = [int(input()) for _ in range(k)] # Read the input numbers into a list

if a[-1]!= 2: # Check if the last number in the list is 2
    print(-1) # If not, print -1 and exit the program
    exit(0)

max_val = 3 # Initialize the maximum value
min_val = 2 # Initialize the minimum value

for i in range(k - 2, -1, -1): # Iterate through the list from the second last number to the first number
    if a[i] > max_val: # If the current number is greater than the maximum value, print -1 and exit the program
        print(-1)
        exit(0)
    else:
        max_val = ((max_val // a[i]) + 1) * a[i] - 1 # Update the maximum value based on the current number

    if min_val % a[i]!= 0: # If the current number does not divide the minimum value evenly, update the minimum value
        min_val = ((min_val // a[i]) + 1) * a[i]

    if max_val <= min_val: # Check if the minimum value is less than or equal to the maximum value
        print(-1) # If so, print -1 and exit the program
        exit(0)

print(min_val, max_val) # Print the minimum and maximum values

