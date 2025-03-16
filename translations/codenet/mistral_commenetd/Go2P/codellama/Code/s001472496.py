
# Initialize an empty string variable to store the input string
s = ""

# Read the input string from the standard input using input() function
s = input()

# Initialize two integer variables max_tmp and max with zero values
max_tmp = 0
max = 0

# Iterate through each character in the input string using a for loop
for i in range(len(s)):
    # Initialize a boolean variable flag with false value
    flag = False

    # Check the character type using if statement
    if s[i] == "A" or s[i] == "C" or s[i] == "T" or s[i] == "G":
        # Increment the max_tmp variable by 1 for each valid character encountered
        max_tmp += 1
    else:
        # Set the flag variable to true if the character is not a valid nucleotide
        flag = True

    # Check if the current character is the last character in the input string
    if i == len(s) - 1:
        # Set the flag variable to true if the current character is the last character
        flag = True

    # If the flag variable is true, then the current character is not a valid nucleotide
    # So, we need to check if the max variable is less than the max_tmp value
    # If yes, then update the max variable with the max_tmp value
    if flag == True:
        if max < max_tmp:
            max = max_tmp
        # Reset the max_tmp variable to zero as we have processed the current sequence of valid nucleotides
        max_tmp = 0

# Print the maximum length of a valid sequence of nucleotides found in the input string
print(max)

# End of the code
