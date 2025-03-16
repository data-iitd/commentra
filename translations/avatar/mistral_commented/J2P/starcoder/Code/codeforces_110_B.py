
import sys ; // Import the sys module to read input from the standard input stream

def main ( ):
  n = int ( sys.stdin.readline ( ) ) ; // Read an integer `n` from the standard input using the readline method of the sys module
  c = [ ] ; // Create a new empty list to store the characters
  p = 'a' ; // Declare a character variable `p` to store the current character to be added to the list

  for i in range ( 4 ) : # Use a for loop to iterate through the first four elements of the list
    for j in range ( i, n, 4 ) : # Use a nested for loop to populate every fourth element of the list with the next character
      c [ j ] = p ; # Set the current element of the list to the current character
      p = chr ( ord ( p ) + 1 ) # Increment the character to be added to the next element

  for i in range ( n ) : # Use a for loop to print each character in the list to the standard output
    print ( c [ i ], end = '' )

  return

if __name__ == '__main__' :
  main ( )

