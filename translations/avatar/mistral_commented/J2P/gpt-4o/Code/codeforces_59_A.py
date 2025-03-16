# Importing the necessary module for reading input
word = input()  # Reading the first word as input from the user

uppercase = 0  # Initializing a counter for uppercase characters
lowercase = 0  # Initializing a counter for lowercase characters

for ch in word:  # Iterating through each character in the word
    if ch.isupper():  # Checking if the character is uppercase
        uppercase += 1  # Incrementing the uppercase counter
    else:
        lowercase += 1  # Incrementing the lowercase counter

if uppercase > lowercase:  # Checking if there are more uppercase characters than lowercase characters
    print(word.upper())  # Printing the word in uppercase if condition is true
elif lowercase > uppercase:  # Checking if there are more lowercase characters than uppercase characters
    print(word.lower())  # Printing the word in lowercase if condition is true
else:  # If both uppercase and lowercase characters are equal
    print(word.lower())  # Printing the word in lowercase if both conditions are false

# <END-OF-CODE>
