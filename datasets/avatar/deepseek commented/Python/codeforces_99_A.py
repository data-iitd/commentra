
l = input ( )  # Taking an input from the user
l = l.split ( '.' )  # Splitting the input into a list of strings separated by a period (.)
s = list ( l [ 0 ] )  # Converting the first part of the split input into a list of characters
p = list ( l [ 1 ] )  # Converting the second part of the split input into a list of characters
i = int ( p [ 0 ] )  # Converting the first character of the second part into an integer

# Checking if the last character of the first part is '9'
if s [ len ( s ) - 1 ] == '9' :
    print ( "GOTO Vasilisa." )  # Printing "GOTO Vasilisa." if the last character is '9'

# Checking if the last character of the first part is not '9' and the integer from the second part is less than 5
elif s [ len ( s ) - 1 ] != '9' and i < 5 :
    s = "".join ( s )  # Joining the first part into a string
    print ( s )  # Printing the joined string

# If the last character of the first part is not '9' and the integer from the second part is 5 or more
else :
    s = "".join ( s )  # Joining the first part into a string
    s = str ( int ( s ) + 1 )  # Incrementing the first part by 1 and converting it back to a string
    print ( s )  # Printing the incremented string

