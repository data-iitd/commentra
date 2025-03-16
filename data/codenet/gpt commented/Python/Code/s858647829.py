# Read two integers from user input and unpack them into variables a and b
a, b = map(int, input().split())

# Check if either a or b is divisible by 3, or if the sum of a and b is divisible by 3
if a % 3 == 0 or b % 3 == 0 or (a + b) % 3 == 0:
    # If any of the above conditions are true, print 'Possible'
    print('Possible')
else:
    # If none of the conditions are met, print 'Impossible'
    print('Impossible') 
