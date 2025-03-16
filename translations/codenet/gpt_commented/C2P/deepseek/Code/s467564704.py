def main():
    # Declare a 4x4 array to hold input values and a variable for test cases
    input_matrix = []
    for _ in range(3):
        row = list(map(int, input().split()))
        input_matrix.append(row)

    # Read the number of test cases
    tc = int(input())

    # Process each test case
    for _ in range(tc):
        testcase = int(input())  # Read the current test case value

        # Check the input array for the testcase value and set it to 0 if found
        for i in range(3):
            for j in range(3):
                if input_matrix[i][j] == testcase:
                    input_matrix[i][j] = 0  # Replace the found value with 0

    # Check for winning conditions in the modified input array
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
        print("No")  # If no winning condition is met, output "No"

# Call the main function
main()
