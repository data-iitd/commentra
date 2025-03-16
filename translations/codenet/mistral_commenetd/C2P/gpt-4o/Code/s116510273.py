# Include necessary libraries for standard input/output and string manipulation

def main():
    mes = input()  # Read a string from the standard input and store it in 'mes'

    # Logic starts here
    print(f"{mes[0]}{len(mes) - 2}{mes[-1]}")  # Print the first character, length - 2 and last character of the input string

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
