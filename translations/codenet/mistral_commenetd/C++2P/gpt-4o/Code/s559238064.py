# Initialize input/output streams and read input data
def main():
    z = input()  # Read input string from standard input
    a = len(z)   # Assign size of the string to variable 'a'

    # Check if there are any consecutive identical characters in the string
    for i in range(a - 1):
        # Check if current character is same as next character
        if z[i] == z[i + 1]:
            # If yes, print "Bad" and exit the program
            print("Bad")
            return

    # If no consecutive identical characters are found, print "Good"
    print("Good")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
