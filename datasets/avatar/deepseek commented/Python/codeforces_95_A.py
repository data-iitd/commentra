
pya = int(input())  # Read the number of inputs to be taken
arre = []  # Initialize an empty list to store the inputs

# Read pya number of inputs and convert them to lowercase, then append to arre
while pya:
    pya -= 1  # Decrement pya by 1 in each iteration
    arre.append(input().lower())

oString = input()  # Read the original string
lowString = oString.lower()  # Convert the original string to lowercase

# Read the first letter and determine the second letter
letter1 = input()[0].lower()
letter2 = 'a' if letter1.lower() != 'a' else 'b'

# Initialize a list of zeros with the length of oString
valid = [0 for i in range(len(oString))]
setcito = set()  # Initialize an empty set to store indices

# Iterate over each string in arre and check if it exists in lowString
for x in arre:
    if lowString.find(x) >= 0:  # Check if the substring is found
        wat = 0
        while True:
            index = lowString.find(x, wat)  # Find the index of the substring
            if index < 0:
                break
            for i in range(index, index + len(x)):
                setcito.add(i)  # Add the indices to the set
            wat = index + 1

# Convert oString to a list for easy manipulation
oString = list(oString)

# Update the characters in oString based on the setcito indices and letter rules
for i in setcito:
    letter = letter1 if lowString[i] != letter1 else letter2
    oString[i] = letter if oString[i].islower() else letter.upper()

# Print the modified oString
for x in oString:
    print(x, end="")
print()