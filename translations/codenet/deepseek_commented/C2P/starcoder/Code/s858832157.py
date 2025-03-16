#include <stdio.h>  # Include the standard input/output library

i = 1
while True:
    Input = int(input())  # Read an integer from the user
    if Input == 0:
        break
    print("Case %d: %d" % (i, Input))  # Print the current case number and input value
    i += 1

# 