# Start of the main function
B = input()  # Read a character from the standard input

# Logic block to determine the output character based on the input character
if B == 'A':  # If the input character is 'A'
    OUT = 'T'  # Set the output character to 'T'
elif B == 'T':  # If the input character is 'T'
    OUT = 'A'  # Set the output character to 'A'
elif B == 'C':  # If the input character is 'C'
    OUT = 'G'  # Set the output character to 'G'
else:  # If the input character is neither 'A', 'T', nor 'C'
    OUT = 'C'  # Set the output character to the input character itself

print(OUT)  # Output the result character to the standard output
# <END-OF-CODE>
