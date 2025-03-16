import sys; # Importing the sys module to read input from the console

t = int(sys.stdin.readline()); # Reading the number of test cases
count = 0; # Initializing a counter to keep track of valid cases

# Looping through each test case
while t > 0:
    a = int(sys.stdin.readline()); # Reading the first integer
    b = int(sys.stdin.readline()); # Reading the second integer
    c = int(sys.stdin.readline()); # Reading the third integer
    
    # Checking if at least one of the integers is equal to 1
    if ((a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1)):
        count += 1; # Incrementing the count if the condition is met
    
    t -= 1; # Decrementing the test case count

# Outputting the total count of valid cases
print(count);

