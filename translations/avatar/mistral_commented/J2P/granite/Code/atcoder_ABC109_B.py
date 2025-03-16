

N = int ( input ( ) )  # Reading the number of strings from the input

map = dict ( )  # Creating an empty dictionary to store strings

for i in range ( N ) :  # Loop to read strings from the input and store them in the dictionary
    map [ i ] = input ( )

ans = True  # Initializing a boolean variable to store the result of the check
past = dict ( )  # Creating an empty dictionary to store the previous strings
next = ""  # Initializing a string variable to store the next character of the current string

for i in range ( N ) :  # Loop to check for the condition
    if ( next in past.values ( ) ) :  # Checking if the current string is already in the dictionary
        ans = False
        break
    past [ i ] = map [ i ]  # Storing the current string in the dictionary

    if ( i!= 0 ) :  # Checking if it's not the first iteration of the loop
        if ( not next.equals ( map [ i ].substring ( 0, 1 ) ) ) :  # Checking if the current string starts with the same character as the previous string
            ans = False
            break
    next = map [ i ].substring ( len ( map [ i ] ) - 1, len ( map [ i ] ) )  # Storing the last character of the current string in the next variable

if ( ans ) :  # Printing "Yes" if the condition is satisfied
    print ( "Yes" )
else :  # Printing "No" if the condition is not satisfied
    print ( "No" )
