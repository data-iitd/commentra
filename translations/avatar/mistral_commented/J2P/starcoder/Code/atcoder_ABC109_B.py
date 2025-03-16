
import java.util.HashMap ;  // Importing HashMap and Scanner classes
import java.util.Scanner ;

def main ( ):
    sc = Scanner ( ) ;  // Creating a Scanner object to read input
    N = sc.nextInt ( ) ;  // Reading the number of strings from the input

    map = HashMap ( ) ;  // Creating an empty HashMap to store strings

    for i in range ( N ) :  // Loop to read strings from the input and store them in the HashMap
        map.put ( i, sc.next ( ) ) ;

    ans = True ;  // Initializing a boolean variable to store the result of the check
    past = HashMap ( ) ;  # Creating an empty HashMap to store the previous strings
    next = "" ;  # Initializing a string variable to store the next character of the current string

    for i in range ( N ) :  # Loop to check for the condition
        if past.containsValue ( map.get ( i ) ) :  # Checking if the current string is already in the HashMap
            ans = False
            break
        past.put ( i, map.get ( i ) ) ;  # Storing the current string in the HashMap

        if i!= 0 :  # Checking if it's not the first iteration of the loop
            if not next.equals ( map.get ( i ) [ 0 ] ) :  # Checking if the current string starts with the same character as the previous string
                ans = False
                break
        next = map.get ( i ) [ -1 ] ;  # Storing the last character of the current string in the next variable

    if ans :  # Printing "Yes" if the condition is satisfied
        print ( "Yes" ) ;
    else :  # Printing "No" if the condition is not satisfied
        print ( "No" ) ;

main ( ) ;

