
import math

def main ( ) : 
    # Read input string from the user
    str = input ( ) 

    # Find the index of the dot ('.') in the string
    dotIndex = 0 
    for i in range ( len ( str ) ) : 
        if str [ i ] == '.' : 
            dotIndex = i 
            break 

    # Check if the character before the dot is '9'
    if str [ dotIndex - 1 ] == '9' : 
        print ( "GOTO Vasilisa." ) 

    # If the character before the dot is not '9', check the digit after the dot
    elif int ( str [ dotIndex + 1 ] ) > 4 : 
        # Increment the number before the dot by 1 and print the result
        _str = "" 
        for i in range ( dotIndex ) : 
            _str += str [ i ] 
        print ( int ( _str ) + 1 ) 

    # If the digit after the dot is 4 or less, print the number before the dot without any changes
    else : 
        for i in range ( dotIndex ) : 
            print ( str [ i ], end = "" ) 
        print ( ) 

main ( ) 

