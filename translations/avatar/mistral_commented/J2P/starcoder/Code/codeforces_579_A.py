
import sys ; // Importing the necessary classes for using sys and stdin from the Python standard library.

def main ( ):
    n = int ( sys.stdin.readline ( ) ) ; // Reading the first integer input n from the user using the readline() method of the sys module.

    s = "" ; // Initializing an empty string variable s to store the binary representation of the number n.

    while ( n > 0 ) :
        x = n % 2 ; // Calculating the last bit of the binary representation of n by finding the remainder of n divided by 2.
        n = n // 2 ; // Updating the value of n by dividing it by 2 to get the next bit of the binary representation.
        s += str ( x ) ; // Appending the calculated bit to the string s.

    ans = 0 ; // Initializing an integer variable ans to 0 to store the number of 1's in the binary representation of n.

    for i in range ( len ( s ) ) : # Starting a for loop that iterates through each character in the string s.
        if ( s [ i ] == '1' ) : # Checking if the current character is '1'.
            ans += 1 ; # If the character is '1', incrementing the value of ans by 1.

    print ( ans ) ; # Printing the value of ans to the standard output stream using the print() function.

    return ; # Returning from the main function.

if __name__ == '__main__' :
    main ( ) ; # Calling the main function to execute the program.

