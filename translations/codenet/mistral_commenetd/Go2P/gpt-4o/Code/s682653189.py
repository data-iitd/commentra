# This file is part of the main module.

# The main function is the entry point of the program.
def main():
    # Initialize a variable "s" of type string.
    s = input()  # Read a single string from the standard input (usually the keyboard) and store it in the variable "s".

    # Iterate through each character in the string "s" using a for loop.
    for i in range(len(s)):
        # Print the character 'x' for each character in the string "s".
        print("x", end="")

    # Print a newline character to the standard output.
    print("")

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
