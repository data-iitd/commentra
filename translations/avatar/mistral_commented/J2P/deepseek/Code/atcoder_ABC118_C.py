import sys

# Define a function to apply the logic to the list
def func(A):
    a = A.copy()  # Create a copy of the list to modify it without affecting the original one
    min_val = 0

    # Iterate through the list and apply the logic to each element
    for i in range(len(a)):
        if a[i] == 0:  # If the current element is 0, remove it and decrease the index of the for loop
            a.pop(i)
            i -= 1
        else:
            if min_val != 0:  # If there is already a minimum value, apply the modulo operation and check if the result is 1
                a[i] = a[i] % min_val
                if a[i] == 1:  # If the result is 1, print 1 and exit the program
                    print(1)
                    sys.exit()
            else:  # If there is no minimum value yet, assign the current element as the minimum value
                min_val = a[i]

    # Sort the list in ascending order and return it
    a.sort()
    return a

# Read the first integer from the input
n = int(input().strip())

# Check if the input is 1, if so, print the only integer and exit the program
if n == 1:
    print(int(input().strip()))  # Print the only integer
    sys.exit()  # Exit the program

# Initialize a list to store the integers
a = list(map(int, input().strip().split()))

# Sort the list in ascending order
a.sort()

# Check if the last integer in the list is 0, if so, print 0 and exit the program
if a[-1] == 0:
    print(0)  # Print 0
    sys.exit()  # Exit the program

# Initialize the answer variable
ans = 0

# Use a while loop to keep applying the function to the list until it contains only one element
while True:
    if len(a) == 1:
        ans = a[0]  # Assign the only remaining integer to the answer variable
        break  # Exit the loop
    a = func(a)  # Apply the function to the list and assign the result back to it

# Print the answer
print(ans)

