# Read a line of input, split it into components, and convert each component to an integer, storing them in a tuple
ABC = tuple(map(int, input().split()))

# Check if the number 5 appears exactly twice in the tuple
if ABC.count(5) == 2:
    # If 5 appears twice, check if the sum of the numbers in the tuple equals 17
    print('YES' if sum(ABC) == 17 else 'NO')
else:
    # If 5 does not appear exactly twice, print 'NO'
    print('NO')
