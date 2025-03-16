

# The main function is the starting point of the program
def main():
    n = input() # The input function is used to read a string of characters from the standard input stream

    # Check if the first three characters of the input string form an identical sequence
    if((n[0]==n[1]) and (n[1]==n[2])) or ((n[1]==n[2]) and (n[2]==n[3])):
        # If the condition is true, print "Yes" to the standard output stream
        print("Yes")
    else:
        # If the condition is false, print "No" to the standard output stream
        print("No")

# Call the main function to execute the program
main()

