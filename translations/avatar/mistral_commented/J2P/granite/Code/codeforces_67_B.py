

import sys

def main ( ) :
  n = int ( input ( ) )  # Reading the number of elements in the array 'bb' from the standard input
  k = int ( input ( ) )  # Reading the value of 'k' from the standard input
  bb = [ int ( x ) for x in input ( ).split ( ) ]  # Reading each element of the array 'bb' from the standard input

  aa = [ ]  # Creating an empty list 'aa' to store the elements of the array 'aa'
  m = 0  # Initializing an integer variable'm' to keep track of the index of the last element added to 'aa'

  for a in range ( n - 1, - 1, - 1 ) :  # Iterating through the array 'bb' from the last index to the first index
    j = 0
    while ( bb [ a ] > 0 ) :  # While there are still elements in 'bb' at index 'a' to be processed
      if ( aa [ j ] >= a + k ) :  # Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
        bb [ a ] -= 1  # If true, decrement the number of elements in 'bb' at index 'a'
      j += 1

    for j_ in range ( m, j - 1, - 1 ) :  # Iterating through the array 'aa' from the last index added to the current index 'j'
      aa [ j_ ] = aa [ j_ - 1 ]  # Swapping the elements at indices 'j_' and 'j_ - 1'

    aa [ j ] = a  # Adding the current index 'a' to the array 'aa' at index 'j'

  print ( " ".join ( map ( lambda x : str ( x + 1 ), aa ) )  # Printing each element of the array 'aa' to the console

main ( )  # Calling the main function of the Python program

These comments should provide a clear understanding of the logic behind each block of code. Let me know if you need any further clarification or modifications.