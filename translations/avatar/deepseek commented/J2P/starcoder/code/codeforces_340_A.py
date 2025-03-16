import sys; # Import the sys module to read input from the user

x = int(sys.stdin.readline()); # Read the first integer input
y = int(sys.stdin.readline()); # Read the second integer input
a = int(sys.stdin.readline()); # Read the third integer input
b = int(sys.stdin.readline()); # Read the fourth integer input

j = 2; # Initialize variables
c = 0;
ans = True;

# Calculate the maximum of x and y and store it in c
c = max(x, y);

# If c is greater than b, print "0" and set ans to false
if (c > b):
    print("0");
    ans = False;

# Continue looping until c is divisible by the minimum of x and y or ans is false
while (c % min(x, y)!= 0 and ans):
    if (x > y):
        c = x * j; # Update c to be x multiplied by j
    else:
        c = y * j; # Update c to be y multiplied by j
    j += 1; # Increment j
    
    # If the updated c is greater than b, print "0" and break out of the loop
    if (c > b):
        print("0");
        ans = False;
        break;

# If ans is still true, calculate the number of multiples of c between a and b
if (ans):
    count = 0;
    i = a;
    for (i = a; i <= b; i++):
        if (i % c == 0): break; # Break if a multiple of c is found
    if (i!= b + 1): 
        print(((b - i) / c) + 1); # Print the number of multiples
    else 
        print("0");

# 