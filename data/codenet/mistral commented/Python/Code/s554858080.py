# User input as a list of strings
input = list(map(str, input().split()))

# Convert list to a single string
num = ''.join(input)

# Check if the length of the string 'num' is evenly divisible by 4
if len(num) % 4 == 0:
    # If the condition is true, print 'YES'
    print('YES')
else:
    # If the condition is false, print 'NO'
    print('NO')