# Importing the standard input/output library is not necessary in Python

def main():  # Main function declaration
    x = int(input("Enter a number: "))  # Reading an integer value from the user and storing it in variable x
    y = x * x * x  # Assigning the value of x cubed to variable y
    print(f"The cube of {x} is {y}")  # Printing the message with the input number and its cube

if __name__ == "__main__":  # Ensuring the main function runs only when the script is executed directly
    main()

# <END-OF-CODE>
