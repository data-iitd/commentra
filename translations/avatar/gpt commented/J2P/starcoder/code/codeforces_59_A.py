# Importing the Scanner class for user input
import java.util.Scanner;

# Creating a Scanner object to read input from the user
in = java.util.Scanner(System.in);

# Prompting the user to enter a word
word = in.next();

# Initializing counters for uppercase and lowercase letters
uppercase = 0;
lowercase = 0;

# Looping through each character in the input word
for i in range(0, word.length()):
    ch = word.charAt(i); # Getting the character at the current index
    
    # Checking if the character is uppercase
    if (Character.isUpperCase(ch)):
        uppercase++; # Incrementing the uppercase counter
    else:
        lowercase++; # Incrementing the lowercase counter

# Comparing the counts of uppercase and lowercase letters
if (uppercase > lowercase):
    # If there are more uppercase letters, print the word in uppercase
    print(word.toUpperCase());
elif (lowercase > uppercase):
    # If there are more lowercase letters, print the word in lowercase
    print(word.toLowerCase());
else:
    # If the counts are equal, print the word in lowercase
    print(word.toLowerCase());

# 