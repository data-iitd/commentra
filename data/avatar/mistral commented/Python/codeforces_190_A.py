#######
# Code
#######

# Read input as two integers n and m
n, m = map(int, input().split())

# Check if both n and m are less than 1
if n < 1:
    # If yes, print n and m and quit the program
    if m < 1:
        print(n, m)
        quit()
    # If not, print "Impossible" and quit the program
    print("Impossible")
    quit()

# Check if m is greater than n
if m > n:
    # If yes, calculate the minimum and maximum values
    min = m
    max = n + m - 1
    # Print the minimum and maximum values
    print(min, max)

# If m is less than or equal to n
if m <= n:
    # Calculate the minimum and maximum values
    min = n
    max = n + m - 1
    # If m is 0, adjust the maximum value accordingly
    if m == 0:
        max = n
    # Print the minimum and maximum values
    print(min, max)
