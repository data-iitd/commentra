
# Declare variables
c = input() # Read a string from the standard input and store it in the 'c' variable
ans = "" # An array to store the output string

# Process the string
for i in range(len(c)): # Iterate through each character in the string 'c'
    if c[i]!= "B": # If the current character is not 'B'
        ans += c[i] # Append the character to the output string 'ans'
    else: # If the current character is 'B'
        ans = ans[:-1] # Remove the last character from the output string 'ans'

# Print the output
print(ans) # Print the final output string

# 