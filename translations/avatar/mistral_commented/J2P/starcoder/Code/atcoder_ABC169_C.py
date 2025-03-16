
# Importing 'Scanner' class to read input from the console
# and 'ArrayList' class to create an array
from java.util import Scanner, ArrayList

# Creating an object of 'Scanner' class
sc = Scanner()

# Reading input from the console
a = sc.nextLong()
b = sc.next()

# Creating an array list
bChar = ArrayList()

# Adding elements to the array list
for i in range(len(b)):
    bChar.add(b[i])

# Creating an empty string
bStr = ""

# Iterating through the array list
for i in range(len(bChar)):
    # Checking if the current character is not '.'
    if bChar[i]!= '.':
        # If the current character is not '.', add it to the string
        bStr += bChar[i]

# Converting the string to an integer
bInt = int(bStr)

# Calculating the result
result = (a * bInt) / 100

# Printing the result
print(result)

