# Declare a 4x4 array to hold input values and a variable for test cases
input_array = [[0] * 4 for _ in range(4)]

# Read 3x3 input values from the user
for i in range(3):
    for j in range(3):
        input_array[i][j] = int(input())  # Store each input value in the array

# Read the number of test cases
tc = int(input())
testcase = 0

# Process each test case
for _ in range(tc):
    testcase = int(input())  # Read the current test case value

    # Check the input array for the testcase value and set it to 0 if found
    for i in range(3):
        for j in range(3):
            if input_array[i][j] == testcase:
                input_array[i][j] = 0  # Replace the found value with 0

# Check for winning conditions in the modified input array
if (input_array[0][0] == 0 and input_array[1][1] == 0 and input_array[2][2] == 0) or \
   (input_array[0][2] == 0 and input_array[1][1] == 0 and input_array[2][0] == 0) or \
   (input_array[0][0] == 0 and input_array[0][1] == 0 and input_array[0][2] == 0) or \
   (input_array[1][0] == 0 and input_array[1][1] == 0 and input_array[1][2] == 0) or \
   (input_array[2][0] == 0 and input_array[2][1] == 0 and input_array[2][2] == 0) or \
   (input_array[0][0] == 0 and input_array[1][0] == 0 and input_array[2][0] == 0) or \
   (input_array[0][1] == 0 and input_array[1][1] == 0 and input_array[2][1] == 0) or \
   (input_array[0][2] == 0 and input_array[1][2] == 0 and input_array[2][2] == 0):
    print("Yes")
else:
    print("No")  # If no winning condition is met, output "No"

# End of the program
# <END-OF-CODE>
