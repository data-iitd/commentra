# Declare a function to check the validity of the input string
def check_validity(s):
    # Initialize a flag to track validity
    flag = 0
    
    # Iterate through each character in the string
    for i in range(len(s)):
        # Check if the index is even
        if i % 2 == 0:
            # Check for valid characters at even indices
            if s[i] not in ['R', 'U', 'D']:
                flag = 1
        else:
            # Check for valid characters at odd indices
            if s[i] not in ['L', 'U', 'D']:
                flag = 1
    
    # Check the flag to determine if the input string was valid
    if flag == 0:
        # If flag is still 0, print "Yes" indicating valid input
        print("Yes")
    else:
        # If flag is set, print "No" indicating invalid input
        print("No")

# Read a string from standard input
s = input().strip()

# Call the function with the input string
check_validity(s)

# <END-OF-CODE>
