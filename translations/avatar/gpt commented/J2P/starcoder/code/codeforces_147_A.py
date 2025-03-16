
# Method to check if a character is a lowercase Latin letter
def isLatinLetter(c):
    return c >= 'a' and c <= 'z' # Returns true if c is between 'a' and 'z'

# Method to check if a character is a punctuation mark
def isPunctuation(c):
    # Check for specific punctuation characters
    if c == '.': return True
    if c == ',': return True
    if c == '!': return True
    if c == '?': return True
    return False # Returns false if c is not a recognized punctuation

# Create a BufferedReader to read input from the console
br = BufferedReader(InputStreamReader(System.in))
# Create a PrintWriter to output results to the console
pw = PrintWriter(System.out)

# Read a line of input from the user
s = br.readLine()
# Initialize a StringBuilder to construct the output string
sb = StringBuilder()
n = len(s) # Get the length of the input string

# Append the first character of the input string to the StringBuilder
sb.append(s[0])

# Loop through the input string starting from the second character
for i in range(1, n):
    c = s[i] # Get the current character
    
    # Check if the current character is a Latin letter
    if isLatinLetter(c):
        # If the previous character is not a Latin letter, append a space
        if not isLatinLetter(s[i - 1]):
            sb.append(' ')
        # Append the current Latin letter to the StringBuilder
        sb.append(c)
    # Check if the current character is a punctuation mark
    elif isPunctuation(c):
        sb.append(c) # Append the punctuation mark to the StringBuilder

# Print the constructed output string
pw.println(sb)
pw.flush() # Ensure all output is written to the console
pw.close() # Close the PrintWriter

