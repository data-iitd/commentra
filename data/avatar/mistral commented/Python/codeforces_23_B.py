# Take an integer input from the user and assign it to the variable n
n = int(input())

# Iterate n times
for i in range(n):
    # Take an integer input from the user and assign it to the variable a
    a = int(input())

    # Check if a is less than 2
    if a < 2:
        # If a is less than 2, print 0
        print(0)

        # Move to the next iteration of the loop
        continue

    # If a is not less than 2, check if it is greater than or equal to 2
    if a >= 2:
        # If a is greater than or equal to 2, print a - 2
        print(a - 2)
