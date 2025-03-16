
# Comment 1: Imports the random module
import random

# Comment 2: Optimizes input/output streams
# Comment 3: Reads the size of the array p from standard input
n = int(input())

# Comment 4: Populates the array p with n integers from standard input
p = [int(input()) for i in range(n)]

# Comment 5: Initializes the variable ans to 0
ans = 0

# Comment 6: Loops through the array p
for i in range(n - 2):
    # Comment 7: Checks for a peak and increments ans
    if p[i] > p[i+1] and p[i+1] > p[i+2]:
        ans += 1
    # Comment 8: Checks for a valley and increments ans
    if p[i] < p[i+1] and p[i+1] < p[i+2]:
        ans += 1

# Comment 9: Prints the final value of ans to standard output
print(ans)

# Comment 10: Ends the program by returning 0
return 0

