# Declare a 2D list `input` of size 3x3 and an integer `tc` to store the number of test cases.
input = [[0]*3 for _ in range(3)]
tc = int(input("Enter number of test cases: "))

# Use a nested for loop to read the elements of the `input` array from the standard input.
for i in range(3):
    for j in range(3):
        input[i][j] = int(input(f"Enter element [{i}][{j}]: "))

# Use another nested for loop to iterate through each test case and check if the given testcase is present in the `input` array or not. If present, we set its value to 0.
for _ in range(tc):
    testcase = int(input("Enter testcase: "))
    for m in range(3):
        for n in range(3):
            if input[m][n] == testcase:
                input[m][n] = 0  # If the given testcase is present in the input array, set its value to 0.

# Check if all the elements of any of the three 1x1 sub-arrays are 0 or not.
if (input[0][0] == 0 and input[1][1] == 0 and input[2][2] == 0) or \
   (input[0][2] == 0 and input[1][1] == 0 and input[2][0] == 0) or \
   (input[0][0] == 0 and input[0][1] == 0 and input[0][2] == 0) or \
   (input[1][0] == 0 and input[1][1] == 0 and input[1][2] == 0) or \
   (input[2][0] == 0 and input[2][1] == 0 and input[2][2] == 0) or \
   (input[0][0] == 0 and input[1][0] == 0 and input[2][0] == 0) or \
   (input[0][1] == 0 and input[1][1] == 0 and input[2][1] == 0) or \
   (input[0][2] == 0 and input[1][2] == 0 and input[2][2] == 0):
    print("Yes")  # If yes, print "Yes" and exit the program.
else:
    print("No")  # If none of the above conditions are satisfied, print "No" and exit the program.

# <END-OF-CODE>
