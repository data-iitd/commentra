
# The main function is the starting point of the program
def main():
    i = 0 # Declare an integer variable 'i'
    alpha = [0] * 26 # Declare an integer array 'alpha' of size 26
    ch = '' # Declare a character variable 'ch'

    # Start an infinite loop
    while True:
        ch = input() # Read a character from the standard input

        # If the character read is End-Of-File (EOF), break the loop
        if ch == '':break

        # If the character is an alphabetic character
        if ch.isalpha():
            # If the character is an uppercase letter, increment the corresponding element in the array 'alpha'
            if ch.isupper():alpha[ord(ch) - 65] += 1

            # If the character is a lowercase letter, increment the corresponding element in the array 'alpha'
            else:alpha[ord(ch) - 97] += 1

    # Initialize the character 'ch' with the ASCII value of 'a'
    ch = 'a'

    # Print the count of each alphabetic character and its corresponding ASCII value
    for i in range(26):
        print(ch, ':', alpha[i])
        ch = chr(ord(ch) + 1)

main() # Call the main function

