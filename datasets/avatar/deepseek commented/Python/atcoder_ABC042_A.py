
ABC = tuple(map(int, input().split()))  # Take input from user, split it into integers, and store in tuple ABC

# Check if the tuple contains exactly two 5s
if ABC.count(5) == 2:
    # Check if the sum of the elements in ABC is 17
    print('YES' if sum(ABC) == 17 else 'NO')
else:
    print('NO')

