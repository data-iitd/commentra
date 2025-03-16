
# Python code to calculate the absolute value of a number

# Macro to calculate the absolute value of a number
def ABS(x):
    return x if x >= 0 else -x

# Read the number of test cases
N = int(input())

# Loop through each test case
for i in range(N):
    # Read the time and coordinates for each test case
    t, x, y = map(int, input().split())

    # Calculate the time left after accounting for the previous time and the distance traveled
    tmp = t - nt - (ABS(x - nx) + ABS(y - ny))

    # Check if the remaining time is negative or odd
    if tmp < 0 or tmp % 2:
        # If so, print "No" and exit the program
        print("No")
        break

    # Update the current position and time for the next iteration
    nt = t # Update the previous time
    nx = x # Update the previous x coordinate
    ny = y # Update the previous y coordinate
else:
    # If all test cases are valid, print "Yes"
    print("Yes")