
import sys ; // Importing sys module for reading input from the console
import re ; // Importing re module for regular expression operations

# Main method is the entry point of the Python application
def main ( ):
  str = sys.stdin.readline ( ).strip ( ) ; # Reading a line of input from the console and stripping it of any leading or trailing whitespaces

  # Finding the index of the last occurrence of '.' character in the string
  dotIndex = re.search ( r"\.", str ).start ( ) ;

  # Checking if the character before the '.' character is '9'
  if ( str [ dotIndex - 1 ] == "9" ):
    print ( "GOTO Vasilisa." ) ; # Printing the message if the condition is true

  # Checking if the character after the '.' character is a digit greater than 4
  elif ( int ( str [ dotIndex + 1 ] ) > 4 ):
    _str = "" ; # Initializing an empty string variable _str

    # Creating a substring of the string str from the beginning to the index of '.' character
    for i in range ( 0, dotIndex ):
      _str += str [ i ] ;

    # Performing big integer addition and printing the result
    print ( int ( _str ) + 1 ) ;

  # Printing the substring of the string str from the beginning to the index of '.' character
  else:
    print ( str [ 0 : dotIndex ] ) ;

  # Printing the end of code comment
  print ( "