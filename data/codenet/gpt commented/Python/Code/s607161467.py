# Read an integer input from the user
R = int(input())

# Check if the input value is less than 1200
if R < 1200:
    # If true, print "ABC"
    print("ABC")
# Check if the input value is less than 2800
elif R < 2800:
    # If true, print "ARC"
    print("ARC")
# If the input value is 2800 or greater
else:
    # Print "AGC"
    print("AGC")
