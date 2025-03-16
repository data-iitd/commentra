import sys

def main():
    # Reading a line of input from the user
    a = sys.stdin.readline().strip()
    
    # Replacing commas in the input string with spaces
    modified_string = a.replace(",", " ")
    
    # Printing the modified string to the console
    print(modified_string)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
