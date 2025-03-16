def main():
    # Reading input from the user
    word = input()
    
    # Initializing counters for uppercase and lowercase letters
    uppercase = 0
    lowercase = 0
    
    # Looping through each character in the input word
    for ch in word:
        # Checking if the character is uppercase
        if ch.isupper():
            uppercase += 1  # Incrementing the uppercase counter
        else:
            lowercase += 1  # Incrementing the lowercase counter
    
    # Comparing the counts of uppercase and lowercase letters
    if uppercase > lowercase:
        # If there are more uppercase letters, print the word in uppercase
        print(word.upper())
    elif lowercase > uppercase:
        # If there are more lowercase letters, print the word in lowercase
        print(word.lower())
    else:
        # If the counts are equal, print the word in lowercase
        print(word.lower())

# Calling the main function
if __name__ == "__main__":
    main()
