
#include<stdio.h>

# The main function is the starting point of the program
def main():
    n = input() # A character array of size 10 is declared to store the input string

    # The scanf function is used to read a string of characters from the standard input stream
    # Check if the first three characters of the input string form an identical sequence
    if((n[0]==n[1])&&(n[1]==n[2]))or((n[1]==n[2])&&(n[2]==n[3])):
        # If the condition is true, print "Yes" to the standard output stream
        print("Yes")
    else:
        # If the condition is false, print "No" to the standard output stream
        print("No")

# The program returns an integer value 0 upon successful execution
if __name__ == "__main__":
    main()

