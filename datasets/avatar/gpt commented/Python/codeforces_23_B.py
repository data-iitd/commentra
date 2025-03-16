# Read an integer input from the user, which represents the number of test cases
n = int(input())

# Loop through each test case
for i in range(n):
    # Read an integer input for the current test case
    a = int(input())
    
    # Check if the input number is less than 2
    if a < 2:
        # If true, print 0 as the output for this case
        print(0)
    
    # Check if the input number is greater than or equal to 2
    if a >= 2:
        # If true, print the result of (a - 2)
        print(a - 2)
