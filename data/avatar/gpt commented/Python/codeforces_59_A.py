# Get input from the user
txt = input()

# Initialize counters for uppercase and lowercase letters
cu = 0  # Counter for uppercase letters
cl = 0  # Counter for lowercase letters

# Iterate through each character in the input text
for z in txt:
    # Check if the character is lowercase
    if z.islower():
        cl = cl + 1  # Increment lowercase counter
    else:
        cu = cu + 1  # Increment uppercase counter

# Compare the counts of uppercase and lowercase letters
if cu > cl:
    # If there are more uppercase letters, convert the text to uppercase
    out = txt.upper()
else:
    # If there are more lowercase letters or they are equal, convert the text to lowercase
    out = txt.lower()

# Print the resulting output
print(out)
