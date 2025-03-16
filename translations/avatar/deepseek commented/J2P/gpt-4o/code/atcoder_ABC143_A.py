import sys  # Importing sys for input operations

def main():  # Defining the main function
    try:  # Beginning of try block to handle potential exceptions
        x = sys.stdin.read().strip().split(" ")  # Reading input and splitting it into a list of strings
        a = int(x[0])  # Converting the first element of the list to an integer
        b = int(x[1])  # Converting the second element of the list to an integer
        c = a - b * 2  # Performing a mathematical operation to calculate a result
        if c < 0: c = 0  # Checking if the result is negative and setting it to 0 if true
        print(c)  # Printing the result to the standard output
    except Exception as e:  # Catch block to handle exceptions
        pass  # Handle exceptions (not implemented in this code)

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
