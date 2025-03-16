# Importing the standard input output library (not needed in Python)

def main():  # Starting the main function
    n = int(input("Enter a number: "))  # Reading an integer value from the standard input

    if n % 1000 == 0:  # Checking if the remainder of `n` when divided by 1000 is equal to 0
        print(0)  # If the condition is true, we print the value 0 to the standard output
    else:
        print((n // 1000 + 1) * 1000 - n)  # If the condition is false, we calculate and print the required value

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
