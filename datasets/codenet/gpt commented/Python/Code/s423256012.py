# Read two integers A and B from user input
A, B = map(int, input().split())

# Check if the sum of A and B is odd
if (A + B) % 2 == 1:
    # If the sum is odd, print 'IMPOSSIBLE' since we cannot split it evenly
    print('IMPOSSIBLE')
else:
    # If the sum is even, calculate and print the average of A and B
    print((A + B) // 2)
