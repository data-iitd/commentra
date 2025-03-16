# Read an integer input which represents the number of strings to be added to the list
pya = int(input())

# Initialize an empty list to store the input strings
arre = []

# Loop to collect 'pya' number of strings from user input
while pya:
    pya -= 1  # Decrement the counter
    # Append the lowercase version of the input string to the list
    arre.append(input().lower())

# Read the original string from user input
oString = input()

# Convert the original string to lowercase for comparison
lowString = oString.lower()

# Read a letter from user input and convert it to lowercase
letter1 = input()[0].lower()

# Determine the second letter based on the first letter; if it's 'a', use 'b', otherwise use 'a'
letter2 = 'a' if letter1.lower() != 'a' else 'b'

# Initialize a list to track valid indices for replacement
valid = [0 for i in range(len(oString))]

# Create a set to store unique indices where replacements will occur
setcito = set()

# Loop through each string in the list 'arre'
for x in arre:
    # Check if the current string 'x' is found in the lowercase version of the original string
    if lowString.find(x) >= 0:
        wat = 0  # Initialize a variable to track the search position
        while True:
            # Find the index of the current string 'x' starting from position 'wat'
            index = lowString.find(x, wat)
            if index < 0:
                break  # Exit the loop if no more occurrences are found
            # Add the indices of the found string to the set for replacement
            for i in range(index, index + len(x)):
                setcito.add(i)
            wat = index + 1  # Move the search position forward

# Convert the original string to a list for mutable operations
oString = list(oString)

# Loop through the indices stored in 'setcito' for replacement
for i in setcito:
    # Determine which letter to use for replacement based on the original character
    letter = letter1 if lowString[i] != letter1 else letter2
    # Replace the character in the original string with the chosen letter, maintaining case
    oString[i] = letter if oString[i].islower() else letter.upper()

# Print the modified string without spaces between characters
for x in oString:
    print(x, end="")

# Print a newline at the end
print()
