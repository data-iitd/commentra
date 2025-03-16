# The main function is the starting point of the program
def main():
    n = input()  # Read a string of characters from the standard input

    # Check if the first three characters of the input string form an identical sequence
    if (len(n) >= 4 and ((n[0] == n[1] == n[2]) or (n[1] == n[2] == n[3]))):
        # If the condition is true, print "Yes" to the standard output
        print("Yes")
    else:
        # If the condition is false, print "No" to the standard output
        print("No")

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
