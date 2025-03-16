# The main function is the entry point of the program
def main():
    # Read a line from standard input and store it in 'buf'
    buf = input()

    # Calculate the length of the string read
    length = len(buf)

    # Print the first character of the string, its length (minus 3), and the last character of the string
    print(f"{buf[0]}{length - 3}{buf[length - 2]}")

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
