import sys

def main():
    # Reading a line of input from the user
    a = sys.stdin.readline()
    
    # Replacing commas in the input string with spaces and printing the modified string
    modified_string = a.replace(",", " ")
    print(modified_string)

if __name__ == "__main__":
    main()
