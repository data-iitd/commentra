# Read a character from the standard input stream
B = input()

# Logic block to determine the output character based on the input character
if B == 'A':
    OUT = 'T'
elif B == 'T':
    OUT = 'A'
elif B == 'C':
    OUT = 'G'
else:
    OUT = B

# Output the result character to the standard output stream
print(OUT)
