#include<stdio.h>

def main():
    # Declare a 4x4 array to hold input values and a variable for test cases
    input = [[0 for x in range(4)] for y in range(4)]
    tc = 0

    # Read 3x3 input values from the user
    for i in range(3):
        for j in range(3):
            input[i][j] = int(input())

    # Read the number of test cases
    tc = int(input())
    testcase = 0

    # Process each test case
    for i in range(tc):
        testcase = int(input())

        # Check the input array for the testcase value and set it to 0 if found
        for i in range(3):
            for j in range(3):
                if(input[i][j] == testcase):
                    input[i][j] = 0

    # Check for winning conditions in the modified input array
    if(input[0][0] == 0 and input[1][1] == 0 and input[2][2] == 0): # Check diagonal from top-left to bottom-right
        print("Yes")
    elif(input[0][2] == 0 and input[1][1] == 0 and input[2][0] == 0): # Check diagonal from top-right to bottom-left
        print("Yes")
    elif(input[0][0] == 0 and input[0][1] == 0 and input[0][2] == 0): # Check first row
        print("Yes")
    elif(input[1][0] == 0 and input[1][1] == 0 and input[1][2] == 0): # Check second row
        print("Yes")
    elif(input[2][0] == 0 and input[2][1] == 0 and input[2][2] == 0): # Check third row
        print("Yes")
    elif(input[0][0] == 0 and input[1][0] == 0 and input[2][0] == 0): # Check first column
        print("Yes")
    elif(input[0][1] == 0 and input[1][1] == 0 and input[2][1] == 0): # Check second column
        print("Yes")
    elif(input[0][2] == 0 and input[1][2] == 0 and input[2][2] == 0): # Check third column
        print("Yes")
    else:
        print("No") # If no winning condition is met, output "No"

if __name__ == "__main__":
    main()

