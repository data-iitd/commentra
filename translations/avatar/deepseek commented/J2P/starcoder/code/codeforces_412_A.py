import sys; # Importing the sys module to read input from the user

n = int(sys.stdin.readline()); # Reading the integer n from the user
k = int(sys.stdin.readline()); # Reading the integer k from the user
a = sys.stdin.readline(); # Reading the string a from the user

# Check if k is greater than n/2
if (k > n / 2):
    # Move right until k equals n
    while (k < n):
        print("RIGHT"); # Print "RIGHT"
        k += 1; # Increment k
else:
    # Move left until k equals 1
    while (k > 1):
        print("LEFT"); # Print "LEFT"
        k -= 1; # Decrement k

# If k equals 1, print each character of the string a starting from the first character and moving rightwards
if (k == 1):
    for i in range(0, a.length()):
        print("PRINT " + a.charAt(i)); # Print the character and then move right
        if ((i + 1) < a.length()):
            print("RIGHT"); # Print "RIGHT" if it's not the last character
else:
    # If k does not equal 1, print each character of the string a starting from the last character and moving leftwards
    for i in range(a.length() - 1, -1, -1):
        print("PRINT " + a.charAt(i)); # Print the character and then move left
        if ((i - 1) >= 0):
            print("LEFT"); # Print "LEFT" if it's not the first character

# 