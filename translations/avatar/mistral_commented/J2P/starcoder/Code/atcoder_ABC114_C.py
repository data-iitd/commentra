
import sys ; // Importing sys module for user input

def main ( ):
    N = int ( sys.stdin.readline ( ).strip ( ) ) ; // Getting the value of N from user input

    i = 357 ; // Initializing the variable i with a value of 357
    c = 0 ; // Initializing the variable c with a value of 0

    while ( i <= N ) : # Starting a while loop that continues as long as i is less than or equal to N
        s = str ( i ) ; # Converting the integer value of i to a string

        if ( "3" in s and "5" in s and "7" in s ) : # Checking if the string contains the digits 3, 5, and 7
            c += 1 ; # Incrementing the value of c by 1 if the condition is true

        sb = "" ; # Creating a new string object
        f = False ; # Initializing a boolean variable f with a value of false

        for j in range ( len ( s ) - 1, -1, -1 ) : # Starting a for loop that iterates through each character in the string s
            a = s [ j ] ; # Getting the character at the current index in reverse order

            if ( f ) : # If the boolean variable f is true, meaning we have found the first occurrence of 3, 5, or 7
                sb += a ; # Appending the current character to the string object
            else : # If the boolean variable f is false, meaning we have not found the first occurrence of 3, 5, or 7 yet
                if ( a == "3" ) : # Checking if the current character is a 3
                    sb += "5" ; # If it is, append a 5 to the string object and set f to true
                    f = True ;
                elif ( a == "5" ) : # Checking if the current character is a 5
                    sb += "7" ; # If it is, append a 7 to the string object and set f to true
                    f = True ;
                else : # If the current character is not a 3, 5, or 7, append a 3 to the string object and set f to true
                    sb += "3" ;
                    f = True ;

        if ( not f ) : sb += "3" ; # If we have not found any 3, 5, or 7 in the string, append a 3 to the string object

        sb2 = sb [ : : -1 ] ; # Creating a new string object from the string object
        i = int ( sb2 [ : : -1 ] ) ; # Converting the reversed string back to a long integer and assigning it to the variable i

    print ( c ) ; # Printing the value of c to the console

if __name__ == "__main__" : main ( ) ; # Running the main function if the file is being run directly

