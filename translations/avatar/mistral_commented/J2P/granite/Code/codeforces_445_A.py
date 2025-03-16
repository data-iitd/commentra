

import sys

# Read input from the standard input stream using a BufferedReader object
buf = sys.stdin.readlines ( )

# Parse the first line of input and split it into an array of strings
inp = buf [ 0 ].split ( "" )

# Parse the first two elements of the array into integers n and m
n = int ( inp [ 0 ] )
m = int ( inp [ 1 ] )

# Create an array ans of size n to store the processed strings
ans = [ ]

# Iterate through each string in the input
for i in range ( n ) :
  str = buf [ i + 1 ].strip ( ) # Read a string from the input
  temp = "" # Initialize an empty string

  # Iterate through each character in the string
  for j in range ( m ) :
    if ( str [ j ] == '-' ) : # If the character is a '-'
      temp += "-" # Append a '-' character to temp
    else :
      if ( ( i + j ) % 2 == 1 ) : # If the index i + j is odd
        temp += "W" # Append 'W' character to temp
      else :
        temp += "B" # Otherwise, append 'B' character to temp

  # Store the final string in the ans array using the index i
  ans.append ( temp )

# Iterate through each string in the ans array and print it to the standard output stream
for i in range ( n ) :
  print ( ans [ i ] )

