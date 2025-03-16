

import sys ; # Importing the sys module to access the standard input and output streams

def cout ( str ) : # Defining a function named cout that takes a String argument and prints it to the console
    print ( str ) ; # Printing the given String to the console

def main ( ) : # Defining the main function that is the entry point of the program
    cin = sys.stdin ; # Creating a new file object named cin to read input from the console
    cout = sys.stdout ; # Creating a new file object named cout to write output to the console

    n = int ( cin.readline ( ) ) ; # Reading an integer value from the console and assigning it to the variable n
    str = cin.readline ( ). strip ( ) ; # Reading a line of text from the console, stripping any leading or trailing whitespace, and assigning it to the variable str

    a = "" ; # Declaring a string variable named a
    for i in range ( n // 2 ) : # Starting a for loop that iterates n/2 times
        a = a + str [ i ] ; # Appending the character at the current index of str to the variable a

    if ( str == a + a ) : # Starting an if statement to check if the given string is a palindrome
        cout ( "Yes" ) ; # Printing "Yes" to the console if the given string is a palindrome
    else :
        cout ( "No" ) ; # Printing "No" to the console if the given string is not a palindrome

if __name__ == "__main__" : # Starting an if statement to check if the script is being run directly
    main ( ) ; # Calling the main function to execute the program

