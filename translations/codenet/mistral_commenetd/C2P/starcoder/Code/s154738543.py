
# Importing the standard input/output library

# Main function declaration and void keyword signifies no arguments
def main():

    x = int(input("Enter a number: ")) # Reading an integer value from the user and storing it in variable x

    y = x * x * x # Assigning the value of x cubed to variable y

    print("The cube of", x, "is", y) # Printing the message with the input number and its cube

if __name__ == "__main__":
    main()

