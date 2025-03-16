#######
# Code
#######

# Read input: two integers n and k
n, k = map(int, input().split())

# Initialize variable x to 0
x = 0

# Check if k is valid based on the condition
if k <= max(n ** 2 // 2, n ** 2 - (n ** 2 // 2)):
    # If k is valid, print 'YES'
    print('YES')

    # Iterate through rows and columns of the grid
    for i in range(n):
        for j in range(n):

            # Check if current position (i, j) is valid based on the condition
            if i % 2 == j % 2 and x < k:

                # If valid, print 'L' and increment x
                print('L', end='')
                x += 1

            # If not valid, print 'S'
            else:
                print('S', end='')

        # Move to the next line after completing a row
        print()

# If k is not valid, print 'NO'
else:
    print('NO')
