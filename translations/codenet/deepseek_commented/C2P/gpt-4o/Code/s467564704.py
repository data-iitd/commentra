# Declare a 3x3 matrix to store the input
input_matrix = [[0]*3 for _ in range(3)]

# Read the 3x3 matrix from the user
for i in range(3):
    for j in range(3):
        input_matrix[i][j] = int(input())

# Read the number of test cases
tc = int(input())

# Loop through each test case
for _ in range(tc):
    # Read the test case value
    testcase = int(input())
    
    # Loop through the matrix to zero out the corresponding elements
    for i in range(3):
        for j in range(3):
            if input_matrix[i][j] == testcase:
                input_matrix[i][j] = 0

# Check for winning conditions for a Tic-Tac-Toe game
if (input_matrix[0][0] == 0 and input_matrix[1][1] == 0 and input_matrix[2][2] == 0) or \
   (input_matrix[0][2] == 0 and input_matrix[1][1] == 0 and input_matrix[2][0] == 0) or \
   (input_matrix[0][0] == 0 and input_matrix[0][1] == 0 and input_matrix[0][2] == 0) or \
   (input_matrix[1][0] == 0 and input_matrix[1][1] == 0 and input_matrix[1][2] == 0) or \
   (input_matrix[2][0] == 0 and input_matrix[2][1] == 0 and input_matrix[2][2] == 0) or \
   (input_matrix[0][0] == 0 and input_matrix[1][0] == 0 and input_matrix[2][0] == 0) or \
   (input_matrix[0][1] == 0 and input_matrix[1][1] == 0 and input_matrix[2][1] == 0) or \
   (input_matrix[0][2] == 0 and input_matrix[1][2] == 0 and input_matrix[2][2] == 0):
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
