
# Import the required libraries
import string

# Function main is the entry point of the program
def main():
    # Initialize an empty string variable 's' to store the input string
    s = ""
    # Read the input string from the standard input using input()
    s = input()
    # Get the length of the input string 's'
    l = len(s)
    # Initialize an answer string 'ans' with the default value "AC"
    ans = "AC"
    # Check if the first character of the input string is not 'A'
    if s[0] != 'A':
        # If it's not, set the answer string to "WA"
        ans = "WA"
    # Initialize a counter 'cnt' to count the number of uppercase characters in the input string
    cnt = 0
    # Iterate through the input string from the second character to the last character
    for i in range(1, l):
        # Check if the current character is an uppercase character
        if s[i].isupper():
            # If it is, check some conditions to determine if the answer is "WA"
            if i == 1 or i == l-1 or s[i] != 'C':
                ans = "WA"
            # If the conditions are not met, increment the counter
            cnt += 1
    # Check if the counter has the expected value (1)
    if cnt != 1:
        # If it doesn't, set the answer string to "WA"
        ans = "WA"
    # Print the answer string to the standard output using print()
    print(ans)
    # End of the code


