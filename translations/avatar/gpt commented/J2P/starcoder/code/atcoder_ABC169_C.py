
# <START-OF-CODE>

# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read a long integer value from the user
a = sc.nextLong()

# Read a string value from the user
b = sc.next()

# Convert the string to a character array for processing
bChar = b.toCharArray()

# Get the length of the character array
length = len(bChar)

# Initialize an empty string to build the integer representation
bStr = ""

# Loop through each character in the character array
for i in range(length):
    # If the character is not a '.', append it to bStr
    if bChar[i]!= '.':
        bStr += bChar[i]

# Convert the built string (bStr) to an integer
bInt = int(bStr)

# Calculate the result by multiplying 'a' with 'bInt' and dividing by 100
result = (a * bInt) / 100

# Print the result to the console
print(result)

# 