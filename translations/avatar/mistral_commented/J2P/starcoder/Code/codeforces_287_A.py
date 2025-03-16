
# Import the Scanner class for reading input
import java.util.Scanner ;

# Define the main method as the entry point of the program
def main ( ):
  sc = java.util.Scanner ( ) ; # Create a new Scanner object to read input from the standard input stream
  str = [ ] ; # Define an array of strings named str with a length of 4 to store the input strings
  i = - 1 ; # Initialize an integer variable i to -1, which will be used as an index to read input strings into the str array

  while ( i!= 3 ) : # Enter a while loop that continues as long as i is not equal to 3
    i = i + 1 ; # Increment i by 1 in each iteration of the loop
    str [ i ] = sc.next ( ) ; # Read the next input string using the Scanner object and store it in the str array at index i

  u = - 1 ; # Initialize an integer variable u to -1, which will be used as an index to compare adjacent strings in the str array

  while ( u!= 2 ) : # Enter an outer while loop that continues as long as u is not equal to 2
    u = u + 1 ; # Increment u by 1 in each iteration of the loop

    yes = 0 ; # Initialize an integer variable yes to 0
    i = - 1 ; # Initialize an integer variable i to -1, which will be used as an index to compare characters in the current and next strings

    while ( i!= 2 ) : # Enter an inner while loop that continues as long as i is not equal to 2
      i = i + 1 ; # Increment i by 1 in each iteration of the loop

      if ( ( str [ u ].charAt ( i ) == str [ u ].charAt ( i + 1 ) and ( str [ u + 1 ].charAt ( i ) == str [ u ].charAt ( i ) or str [ u + 1 ].charAt ( i + 1 ) == str [ u ].charAt ( i ) ) ) or ( str [ u + 1 ].charAt ( i ) == str [ u + 1 ].charAt ( i + 1 ) and ( str [ u ].charAt ( i ) == str [ u + 1 ].charAt ( i ) or str [ u ].charAt ( i + 1 ) == str [ u + 1 ].charAt ( i ) ) ) ) : # Compare the corresponding characters at indices i and i+1 in the current and next strings using the logical operators && and ||
        yes = 1 ; # Set the yes variable to 1 if the condition is true
        print ( "YES" ) ; # Print "YES" to the standard output if the condition is true
        break ; # Break out of both loops using the break statement if the condition is true

    if ( yes == 1 ) : # If the yes variable is set to 1, break out of the outer while loop
      break ;

    if ( yes == 0 ) : # If the yes variable is still equal to 0, print "NO" to the standard output
      print ( "NO" ) ;

# Call the main method
main ( )

