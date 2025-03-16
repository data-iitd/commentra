# Read a string input from the user
str_input = input()

# Check if the characters at positions 2 and 3 are the same,
# and if the characters at positions 4 and 5 are the same
if str_input[2] == str_input[3] and str_input[4] == str_input[5]:
    print("Yes")  # If both conditions are true, output "Yes"
else:
    print("No")   # If either condition is false, output "No"

# <END-OF-CODE>
