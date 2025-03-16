
import java.util.HashMap ; import java.util.Map.Entry ; import java.util.Scanner ; 
# Import statements for Scanner and HashMap

def main ( ):
    in = Scanner ( System.in ) ; 
    # Initialize Scanner object to read input

    s = in.next ( ) ; 
    # Read the input string

    targ = s.toCharArray ( ) ; 
    # Convert the string to a character array

    map = HashMap ( ) ; 
    # Initialize a HashMap to store character counts

    for i in range ( 0, len ( targ ) ) : 
        # Loop through each character in the character array
        if ( not map.containsKey ( targ [ i ] ) ) : 
            # If the character is not already in the map, add it with a count of 1
            map.put ( targ [ i ], 1 ) ; 
        else : 
            # If the character is already in the map, increment its count
            map.put ( targ [ i ], map.get ( targ [ i ] ) + 1 ) ; 

    ok = True ; 
    # Initialize a boolean flag to check the conditions

    for c in map.entrySet ( ) : 
        # Loop through each entry in the HashMap
        if ( c.getValue ( )!= 2 ) : 
            # If any character count is not 2, set ok to false and break the loop
            ok = False ; 
            break ; 

    if ( ok and map.size ( ) == 2 ) : 
        # Check if all characters appear exactly twice and there are exactly 2 unique characters
        print ( "Yes" ) ; 
        # Print "Yes" if the conditions are met
    else : 
        print ( "No" ) ; 
        # Print "No" otherwise

    in.close ( ) ; 
    # Close the Scanner object

if __name__ == "__main__" :
    main ( ) ; 
    # Call the main function

