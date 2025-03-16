# Read a line of input, split it into words, and convert each word to a string
input = list(map(str, input().split()))

# Join the list of strings into a single string
num = ''.join(input)

# Check if the integer representation of the number is divisible by 4
if(int(num) % 4 == 0):
    # If it is divisible by 4, print 'YES'
    print('YES')
else:
    # If it is not divisible by 4, print 'NO'
    print('NO')
