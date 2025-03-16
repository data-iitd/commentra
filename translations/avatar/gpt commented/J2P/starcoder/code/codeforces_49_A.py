# Import the Scanner class for user input
import java.util.Scanner;

# Create a Scanner object to read input from the console
sc = java.util.Scanner(System.in);

# Read a line of input from the user
s = sc.nextLine();

# Get the length of the input string
length = len(s);

# Initialize a character variable to store the last non-space, non-question mark character
ch = 0;

# Loop through the string in reverse to find the last relevant character
for i in range(length - 1, -1, -1):
    # Check if the current character is not a space or a question mark
    if s[i]!='' and s[i]!= '?':
        ch = s[i]; # Store the character
        break; # Exit the loop once the character is found

# Convert the character to lowercase for uniform comparison
ch = ch.lower();

# Check if the character is a vowel or 'y'
if ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'y':
    print("YES"); # Print "YES" if it is a vowel
else:
    print("NO"); # Print "NO" if it is not a vowel

# 