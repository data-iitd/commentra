s = input()  # Read a string from the user input
flag = 0  # Initialize a flag to check for invalid characters

# Loop through each character in the string
for i in range(len(s)):
    if i % 2 == 0:
        # Check if the index is even
        if s[i] not in ('R', 'U', 'D'):
            flag = 1
            break
    else:
        # Check if the index is odd
        if s[i] not in ('L', 'U', 'D'):
            flag = 1
            break

if flag == 0:
    # If no invalid characters were found, print "Yes"
    print("Yes")
else:
    # If invalid characters were found, print "No"
    print("No")

# <END-OF-CODE>
