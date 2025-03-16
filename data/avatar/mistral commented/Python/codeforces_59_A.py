# Get the text input from the user
txt = input()

# Initialize the count of uppercase and lowercase characters
cu = 0
cl = 0

# Iterate through each character in the text input
for z in txt:
    # If the character is lowercase, increment the lowercase count
    if z.islower():
        cl += 1
    # If the character is uppercase, increment the uppercase count
    else:
        cu += 1

# Determine the output based on the count of uppercase and lowercase characters
if cu > cl:
    # If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
    out = txt.upper()
else:
    # If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
    out = txt.lower()

# Print the output
print(out)
