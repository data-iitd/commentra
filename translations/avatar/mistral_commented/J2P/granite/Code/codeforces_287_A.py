

str = [] # Define an empty list named str to store the input strings

for i in range ( 4 ) : # Enter a for loop that iterates 4 times
  str.append ( input ( ) ) # Read the next input string using the input function and append it to the str list

for u in range ( 2 ) : # Enter an outer for loop that iterates 2 times
  yes = 0 # Initialize an integer variable yes to 0
  i = - 1 # Initialize an integer variable i to -1, which will be used as an index to compare characters in the current and next strings

  while i!= 2 : # Enter an inner while loop that continues as long as i is not equal to 2
    i = i + 1 # Increment i by 1 in each iteration of the loop

    if ( ( str [ u ] [ i ] == str [ u ] [ i + 1 ] and ( str [ u + 1 ] [ i ] == str [ u ] [ i ] or str [ u + 1 ] [ i + 1 ] == str [ u ] [ i ] ) ) or ( str [ u + 1 ] [ i ] == str [ u + 1 ] [ i + 1 ] and ( str [ u ] [ i ] == str [ u + 1 ] [ i ] or str [ u ] [ i + 1 ] == str [ u + 1 ] [ i ] ) ) ) : # Compare the corresponding characters at indices i and i+1 in the current and next strings using the logical operators && and ||
      yes = 1 # Set the yes variable to 1 if the condition is true
      print ( "YES" ) # Print "YES" to the standard output if the condition is true
      break # Break out of both loops using the break statement if the condition is true

  if yes == 1 : # If the yes variable is set to 1, break out of the outer for loop
    break

  if yes == 0 : # If the yes variable is still equal to 0, print "NO" to the standard output
    print ( "NO" )

