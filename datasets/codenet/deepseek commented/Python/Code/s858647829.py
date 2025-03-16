
a, b = map(int, input().split())

# Taking two integer inputs from the user

if a % 3 == 0 or b % 3 == 0 or (a + b) % 3 == 0:
    print('Possible')
    # Checking if either a, b, or the sum of a and b is divisible by 3
else:
    print('Impossible')
    # If none of the conditions are met, print 'Impossible'

