#include<stdio.h>
# Declare an integer 2D array `input` of size 4x4 and an integer `tc` to store the number of test cases.
input = [[0 for i in range(4)] for j in range(4)]
tc = 0
# Use a nested for loop to read the elements of the `input` array from the standard input.
for i in range(3):
    for j in range(3):
        input[i][j] = int(input())
        # Read the elements of the input array
for i in range(tc):
    testcase = int(input())
    # Read the number of test cases `tc` from the standard input.
    for m in range(3):
        for n in range(3):
            if input[m][n] == testcase:
                input[m][n] = 0
                # If the given testcase is present in the input array, set its value to 0.
if input[0][0] == 0 and input[1][1] == 0 and input[2][2] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[0][2] == 0 and input[1][1] == 0 and input[2][0] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[0][0] == 0 and input[0][1] == 0 and input[0][2] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[1][0] == 0 and input[1][1] == 0 and input[1][2] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[2][0] == 0 and input[2][1] == 0 and input[2][2] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[0][0] == 0 and input[1][0] == 0 and input[2][0] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[0][1] == 0 and input[1][1] == 0 and input[2][1] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
elif input[0][2] == 0 and input[1][2] == 0 and input[2][2] == 0:
    print("Yes")
    # If yes, print "Yes" and exit the program.
    exit(0)
else:
    print("No")
    # If none of the above conditions are satisfied, print "No" and exit the program.
    exit(1)
