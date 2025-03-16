# Take a string input from the user
s = input ( )

# Initialize an empty string to store the result
result = ""

# Initialize a variable 'i' to traverse the string 's'
i = 0

# Use a while loop to traverse the string 's' until the end
while i < len ( s ) :

    # Check if the current character is a '.'
    if s [ i ] == "." :

        # If yes, append '0' to the result string
        result += '0'

    # Move to the next character if it's not a '.'
    else :

        # Increment the index 'i' to move to the next character
        i += 1

        # Check if the next character is also a '.'
        if s [ i ] == "." :

            # If yes, append '1' to the result string
            result += '1'

        # If not, append '2' to the result string
        else :
            result += '2'

    # Increment the index 'i' to move to the next character
    i += 1

# Print the final result string
print ( result )
