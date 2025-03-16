
# Importing the Scanner class for user input
from java.util import Scanner

# Method to generate a character array from the concatenation of numbers 1 to 1000
def generate_string():
    # Creating a StringBuilder to efficiently build the string
    sb = StringBuilder()

    # Looping through numbers 1 to 1000 and appending them to the StringBuilder
    for i in range(1, 1001):
        sb.append(i)

    # Converting the built string to a character array and returning it
    return sb.toString().toCharArray()

# Reading an integer input from the user
n = Scanner(System.in).nextInt()

# Printing the character at the (n-1)th index of the generated character array
print(generate_string()[n - 1])

# Closing the Scanner to prevent resource leaks
Scanner(System.in).close()

