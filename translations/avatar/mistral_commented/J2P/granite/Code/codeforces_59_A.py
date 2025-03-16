
import sys  # Importing the sys module for reading input from the console

def main ( ):  # Main function, entry point of the program
    word = input ( )  # Reading the first word as input from the user

    uppercase = 0  # Initializing a counter for uppercase characters
    lowercase = 0  # Initializing a counter for lowercase characters

    for ch in word:  # Iterating through each character in the word
        if ch.isupper ( ):  # Checking if the character is uppercase
            uppercase += 1  # Incrementing the uppercase counter
        else:
            lowercase += 1  # Incrementing the lowercase counter

    if uppercase > lowercase:  # Checking if there are more uppercase characters than lowercase characters
        print ( word.upper ( ) )  # Printing the word in uppercase if condition is true
    elif lowercase > uppercase:  # Checking if there are more lowercase characters than uppercase characters
        print ( word.lower ( ) )  # Printing the word in lowercase if condition is true
    else:  # If both uppercase and lowercase characters are equal
        print ( word.lower ( ) )  # Printing the word in lowercase if both conditions are false

if __name__ == "__main__":  # Executing the main function only if the script is run directly
    main ( )  # Calling the main function

