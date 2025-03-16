# Initialize variables
pya = int(input()) # Get the number of strings to be processed
arre = [] # Initialize an empty list to store the strings

# Process strings input
while pya:
    pya -= 1 # Decrement pya by 1
    x = input().lower() # Get the next string as a lowercase string
    arre.append(x) # Append the string to the list

# Get the original string and its first letter
oString = input() # Get the original string
letter1 = input()[0].lower() # Get the first letter of the original string in lowercase

# Determine the second letter based on the first letter
letter2 = 'a' if letter1.lower() != 'a' else 'b' # If the first letter is not 'a', set the second letter to 'b'

# Initialize a list of valid indices and a set to store the indices of the strings in the original string
valid = [0 for i in range(len(oString))] # Initialize a list of zeros with the length of the original string
setcito = set() # Initialize an empty set

# Find the indices of the strings in the original string
for x in arre:
    if oString.lower().find(x) >= 0: # If the original string contains the current string
        for i in range(oString.find(x), len(oString)): # Iterate through the indices of the string in the original string
            setcito.add(i) # Add the index to the set

# Replace the letters in the original string based on the indices of the strings
oString = list(oString) # Convert the string to a list
for i in setcito:
    letter = letter1 if oString[i].islower() != letter1.islower() else letter2 # Determine the letter to replace based on the first letter and the case of the letter at the index
    oString[i] = letter if oString[i].islower() else letter.upper() # Replace the letter with the determined letter, preserving the case

# Print the modified string
for x in oString:
    print(x, end="") # Print each character of the modified string
print() # Print a newline after the modified string
