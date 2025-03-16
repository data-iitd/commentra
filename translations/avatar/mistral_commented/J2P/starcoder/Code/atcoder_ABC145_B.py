
import sys ; // Importing the sys module to read input from the console

def cout ( str ) : // Defining a function named cout that takes a String argument and prints it to the console
    print ( str ) ; // Printing the given String to the console

def main ( ) : // Defining the main function that is the entry point of the program
    cin = sys.stdin ; // Creating a new Scanner object named cin to read input from the console

    a = "" ; b = "" ; str = "" ; // Declaring three String variables: a, b, and str
    n = int ( cin.readline ( ) ) ; // Reading an integer value from the console and assigning it to the variable n

    str = cin.readline ( ) ; // Reading a line of text from the console and assigning it to the variable str

    for i in range ( 0, n // 2 ) : // Starting a for loop that iterates n/2 times
        a = a + str [ i ] ; // Appending the character at the current index of str to the variable a

    if ( str == a + a ) : // Starting an if statement to check if the given string is a palindrome
        cout ( "Yes" ) ; // Printing "Yes" to the console if the given string is a palindrome
    else :
        cout ( "No" ) ; // Printing "No" to the console if the given string is not a palindrome

main ( ) ; // Calling the main function to execute the program

