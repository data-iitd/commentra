
# Taking two integers as input from the user
a, b = map(int, input().split())

# Checking if number 'a' is divisible by 3
if a % 3 == 0:
    # If 'a' is divisible by 3, print 'Possible'
    print('Possible')
    # Exit the loop as the condition is met
    exit()

# Checking if number 'b' is divisible by 3
if b % 3 == 0:
    # If 'b' is divisible by 3, print 'Possible'
    print('Possible')
    # Exit the loop as the condition is met
    exit()

# Checking if sum of 'a' and 'b' is divisible by 3
if (a + b) % 3 == 0:
    # If sum of 'a' and 'b' is divisible by 3, print 'Possible'
    print('Possible')
    # Exit the loop as the condition is met
    exit()

# If none of the above conditions are true, print 'Impossible'
else:
    print('Impossible')