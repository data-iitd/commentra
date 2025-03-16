import sys  # Importing sys for input operations

def main():  # Defining the main function
    a = sys.stdin.read().strip()  # Reading a line of input from the user
    print(a.replace(",", " "))  # Replacing commas with spaces in the input string and printing the result

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
