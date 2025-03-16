
word = input() # Reading a single word from the user input

uppercase = 0 # Initializing the counter for uppercase letters
lowercase = 0 # Initializing the counter for lowercase letters

# Looping through each character in the input word
for ch in word:
    if ch.isupper(): # Checking if the character is uppercase
        uppercase += 1 # Incrementing the uppercase counter
    else:
        lowercase += 1 # Incrementing the lowercase counter

# Comparing the counts of uppercase and lowercase letters and printing the result accordingly
if uppercase > lowercase:
    print(word.upper()) # Printing the word in uppercase if there are more uppercase letters
elif lowercase > uppercase:
    print(word.lower()) # Printing the word in lowercase if there are more lowercase letters
else:
    print(word.lower()) # Printing the word in lowercase if the counts are equal

# 