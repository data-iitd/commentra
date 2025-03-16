str = input() # Read a string input from the user

# Check if the characters at positions 2 and 3 are the same,
# and if the characters at positions 4 and 5 are the same
if str[2] == str[3] and str[4] == str[5]:
    print("Yes") # If both conditions are true, output "Yes"
else:
    print("No") # If either condition is false, output "No"

