
# Take input from the user and split it into a list of strings
input = list(map(str,input().split()))

# Join the list of strings into a single string
num = ''.join(input)

# Check if the number represented by the string is divisible by 4
if(int(num) % 4 == 0):
    # If divisible by 4, print 'YES'
    print('YES')
else:
    # If not divisible by 4, print 'NO'
    print('NO')

