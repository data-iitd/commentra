

str = input ( ) # Reading a line of input from the console and storing it in the string variable str
dotIndex = str.rfind ( '.' ) # Finding the index of the last occurrence of '.' character in the string

# Checking if the character before the '.' character is '9'
if str [ dotIndex - 1 ] == '9' :
  print ( "GOTO Vasilisa." ) # Printing the message if the condition is true

# Checking if the character after the '.' character is a digit greater than 4
elif int ( str [ dotIndex + 1 ] ) > 4 :
  print ( int ( str.split ( '.' ) [ 0 ] ) + 1 ) # Performing big integer addition and printing the result

# Printing the substring of the string variable str from the beginning to the index of '.' character
else :
  print ( str.split ( '.' ) [ 0 ] )

# Printing the comment "