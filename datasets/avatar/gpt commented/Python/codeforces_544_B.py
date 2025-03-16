# Read two integers n and k from input
n, k = map(int, input().split())

# Initialize a counter to keep track of the number of 'L' printed
x = 0

# Check if k is less than or equal to the maximum number of 'L' that can be printed
if k <= max(n ** 2 // 2, n ** 2 - (n ** 2 // 2)):
    # If the condition is satisfied, print 'YES'
    print('YES')
    
    # Iterate over each row of the n x n grid
    for i in range(n):
        # Iterate over each column of the n x n grid
        for j in range(n):
            # Check if the current position (i, j) is in the same parity group and if we can still print 'L'
            if i % 2 == j % 2 and x < k:
                # Print 'L' and increment the counter
                print('L', end='')
                x += 1
            else:
                # Print 'S' if the conditions for 'L' are not met
                print('S', end='')
        # Move to the next line after finishing a row
        print()
else:
    # If k is greater than the maximum possible 'L', print 'NO'
    print('NO')
