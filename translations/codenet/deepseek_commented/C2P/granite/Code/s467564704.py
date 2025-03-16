
# Read the 3x3 matrix from the user
input = [[0 for _ in range(3)] for _ in range(3)]
for i in range(3):
    for j in range(3):
        input[i][j] = int(input())

# Read the number of test cases
tc = int(input())

# Loop through each test case
for _ in range(tc):
    # Read the test case value
    testcase = int(input())

    # Loop through the matrix to zero out the corresponding elements
    for i in range(3):
        for j in range(3):
            if input[i][j] == testcase:
                input[i][j] = 0

# Check for winning conditions for a Tic-Tac-Toe game
if input[0][0] == 0 and input[1][1] == 0 and input[2][2] == 0:
    print("Yes")
elif input[0][2] == 0 and input[1][1] == 0 and input[2][0] == 0:
    print("Yes")
elif input[0][0] == 0 and input[0][1] == 0 and input[0][2] == 0:
    print("Yes")
elif input[1][0] == 0 and input[1][1] == 0 and input[1][2] == 0:
    print("Yes")
elif input[2][0] == 0 and input[2][1] == 0 and input[2][2] == 0:
    print("Yes")
elif input[0][0] == 0 and input[1][0] == 0 and input[2][0] == 0:
    print("Yes")
elif input[0][1] == 0 and input[1][1] == 0 and input[2][1] == 0:
    print("Yes")
elif input[0][2] == 0 and input[1][2] == 0 and input[2][2] == 0:
    print("Yes")
else:
    print("No")

