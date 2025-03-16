
import math
import sys

# Reading a line of input from the console and storing it in the string str
str = sys.stdin.readline ( )

# Finding the index of the last occurrence of '.' character in the string
dotIndex = str.rfind ( '.' )

# Checking if the character before the '.' character is '9'
if str [ dotIndex - 1 ] == '9' :
  print ( "GOTO Vasilisa." )

# Checking if the character after the '.' character is a digit greater than 4
elif int ( str [ dotIndex + 1 ] ) > 4 :
  # Creating a substring of the string str from the beginning to the index of '.' character
  _str = str [ : dotIndex ]

  # Performing big integer addition and printing the result
  print ( str ( int ( _str ) + 1 ) )

# Printing the substring of the string str from the beginning to the index of '.' character
else :
  print ( str [ : dotIndex ] )

# Printing a newline character at the end of the substring
print ( )

