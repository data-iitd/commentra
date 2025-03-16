
import sys ; // Importing sys module for reading input from user

def main ( ):
    s = sys.stdin.readline ( ).strip ( ) ; // Reading a string input from user
    targ = list ( s ) ; // Converting the string input to a list

    map = { } ; // Creating an empty dictionary to store character and their frequency

    for i in range ( len ( targ ) ) :
        currentChar = targ [ i ] ; // Assigning the current character to a variable

        if ( currentChar not in map ) :
            map [ currentChar ] = 1 ; // If not present, adding the current character with frequency 1 to the dictionary
        else :
            map [ currentChar ] += 1 ; // If present, incrementing the frequency of the current character in the dictionary

    ok = True ; // Initializing a boolean variable to check if all characters have frequency 2 or not

    for key, value in map.items ( ) :
        if ( value!= 2 ) :
            ok = False ; # Setting the boolean variable to false if any character has frequency other than 2
            break ; # Exiting the loop if any character has frequency other than 2

    if ( ok and len ( map ) == 2 ) : # Checking if all characters have frequency 2 and the size of the dictionary is 2
        print ( "Yes" ) ; # Printing "Yes" if both conditions are true
    else :
        print ( "No" ) ; # Printing "No" if any character has frequency other than 2 or the size of the dictionary is not 2

if __name__ == "__main__" :
    main ( ) ;

