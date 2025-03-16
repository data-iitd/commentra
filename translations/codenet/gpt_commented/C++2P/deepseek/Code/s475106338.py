# Read the number of test cases
num_test_cases = int(input())

# Loop to process each test case
for _ in range(num_test_cases):
    # Read the type (t) and quantity (n) from input
    t, n = map(int, input().split())

    # Calculate and output the result based on the type (t)
    if t == 1:
        # If type is 1, multiply n by 6000
        print(6000 * n)
    elif t == 2:
        # If type is 2, multiply n by 4000
        print(4000 * n)
    elif t == 3:
        # If type is 3, multiply n by 3000
        print(3000 * n)
    elif t == 4:
        # If type is 4, multiply n by 2000
        print(2000 * n)

# End-of-code comment
