import sys

# Reading the number of test cases
t = int(sys.stdin.readline())

# Initializing a counter to keep track of valid cases
count = 0

# Looping through each test case
while t > 0:
    # Reading the first integer
    a = int(sys.stdin.readline())
    
    # Reading the second integer
    b = int(sys.stdin.readline())
    
    # Reading the third integer
    c = int(sys.stdin.readline())
    
    # Checking if at least one of the integers is equal to 1
    if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
        count += 1 # Incrementing the count if the condition is met
    
    # Decrementing the number of test cases
    t -= 1

# Outputting the total count of valid cases
print(count)

