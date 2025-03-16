txt = input()  # Taking input from the user and storing it in the variable `txt`.
cu = 0  # Initializing the counter for uppercase letters to zero.
cl = 0  # Initializing the counter for lowercase letters to zero.

# Looping through each character in the input text `txt` to count the number of uppercase and lowercase letters.
for z in txt:
    if z.islower():  # Checking if the current character `z` is lowercase.
        cl = cl + 1  # Incrementing the counter for lowercase letters if `z` is lowercase.
    else:  # If `z` is not lowercase, it must be uppercase.
        cu = cu + 1  # Incrementing the counter for uppercase letters.

# Comparing the counts of uppercase and lowercase letters to decide the case of the output.
if cu > cl:  # If there are more uppercase letters than lowercase letters.
    out = txt.upper()  # Convert the entire text to uppercase.
else:  # If there are more lowercase letters than uppercase letters or equal counts.
    out = txt.lower()  # Convert the entire text to lowercase.

print(out)  # Printing the result stored in `out`.
