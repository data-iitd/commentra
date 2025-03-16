# Read a string input from the user
str_input = input()  # Assign the input to the variable 'str_input'

# Check if the third and fourth characters of the string are identical
if str_input[2] == str_input[3]:
    # If the condition is true, proceed to the next check
    if str_input[4] == str_input[5]:  # Check if the fifth and sixth characters are identical
        print("Yes")  # If both conditions are true, print 'Yes'
    else:
        print("No")  # If not, print 'No'

# <END-OF-CODE>
