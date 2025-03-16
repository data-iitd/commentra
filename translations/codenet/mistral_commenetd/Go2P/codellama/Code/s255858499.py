
# Initialize a new scanner to read input from stdin
sc = input()

# Function to read a single line from stdin and return it as a string
def nextLine():
    # Scan the next token as a word
    sc.split()
    # Return the text of the scanned token as a string
    return sc.text()

# Main function
def main():
    # Read the first two integers from stdin and store them in variables a and b
    a = int(nextLine()) # Convert the first line read from stdin to an integer and store it in variable a
    b = int(nextLine()) # Convert the second line read from stdin to an integer and store it in variable b

    # Check if the product of a and b is odd or even
    if a*b%2 != 0:
        # If the product is odd, print "Odd" to stdout
        print("Odd")
    else:
        # If the product is even, print "Even" to stdout
        print("Even")

# END-OF-CODE
