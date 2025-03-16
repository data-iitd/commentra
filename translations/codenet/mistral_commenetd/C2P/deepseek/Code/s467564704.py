def main():
    # Declare an integer 2D array `input` of size 4x4 and an integer `tc` to store the number of test cases.
    input = [[int(x) for x in input().split()] for _ in range(3)]
    tc = int(input())
    
    # Use a nested for loop to iterate through each test case and check if the given testcase is present in the `input` array or not. If present, we set its value to 0.
    for _ in range(tc):
        testcase = int(input())
        for m in range(3):
            for n in range(3):
                if input[m][n] == testcase:
                    input[m][n] = 0
    
    # Check if all the elements of any of the three 1x1 sub-arrays are 0 or not.
    if (input[0][0] == 0 and input[1][1] == 0 and input[2][2] == 0) or \
       (input[0][2] == 0 and input[1][1] == 0 and input[2][0] == 0) or \
       (input[0][0] == 0 and input[0][1] == 0 and input[0][2] == 0) or \
       (input[1][0] == 0 and input[1][1] == 0 and input[1][2] == 0) or \
       (input[2][0] == 0 and input[2][1] == 0 and input[2][2] == 0) or \
       (input[0][0] == 0 and input[1][0] == 0 and input[2][0] == 0) or \
       (input[0][1] == 0 and input[1][1] == 0 and input[2][1] == 0) or \
       (input[0][2] == 0 and input[1][2] == 0 and input[2][2] == 0):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
