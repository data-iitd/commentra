
import sys ; // Importing the utility module sys

def main ( ) :
  N , K = map ( int , input ( ). split ( ) ) ; // Reading the first two integers from the standard input and assigning them to the variables N and K
  S = input ( ) ; // Reading a string from the standard input and assigning it to the variable S

  c1 = list ( S ) ; // Converting the string S to a list c1
  c3 = list ( S ) ; // Converting the string S to a list c3

  flag1 = False ; // Initializing a boolean flag1 to false
  count1 = 0 ; // Initializing an integer counter count1 to zero

  // The first for loop is used to process the list c1
  for i in range ( N ) :
    if flag1 and c1 [ i ] == 'R' : // If flag1 is true and the current character in c1 is 'R'
      flag1 = False ; // Setting flag1 to false
      count1 += 1 ; // Incrementing the counter count1
    if count1 == K : // If the counter count1 has reached the value K
      break ; // Exiting the for loop
    if c1 [ i ] == 'L' : // If the current character in c1 is 'L'
      flag1 = True ; // Setting flag1 to true

  flag3 = False ; // Initializing a boolean flag3 to false
  count3 = 0 ; // Initializing an integer counter count3 to zero

  // The second for loop is used to process the list c3
  for i in range ( N ) :
    if flag3 and c3 [ i ] == 'L' : // If flag3 is true and the current character in c3 is 'L'
      flag3 = False ; // Setting flag3 to false
      count3 += 1 ; // Incrementing the counter count3
    if count3 == K : // If the counter count3 has reached the value K
      break ; // Exiting the for loop
    if c3 [ i ] == 'R' : // If the current character in c3 is 'R'
      flag3 = True ; // Setting flag3 to true

  S1 = ''.join ( c1 ) ; // Creating a new string object S1 from the list c1
  S3 = ''.join ( c3 ) ; // Creating a new string object S3 from the list c3

  count2 = 1 ; // Initializing an integer counter count2 to one
  sum1 = 0 ; // Initializing an integer variable sum1 to zero
  bef1 = S1 [ 0 ] ; // Assigning the first character in the string S1 to the character variable bef1

  # The third for loop is used to find the length of the longest consecutive identical characters in the string S1
  for i in range ( 1 , N ) :
    if S1 [ i ] == bef1 : // If the current character in S1 is the same as the previous character
      count2 += 1 ; // Incrementing the counter count2
    else : # If the current character in S1 is different from the previous character
      sum1 += count2 - 1 ; // Adding the length of the previous consecutive identical characters to the variable sum1, subtracting one
      count2 = 1 ; // Resetting the counter count2 to one
      bef1 = S1 [ i ] ; // Assigning the current character in S1 to the character variable bef1

  sum1 += count2 - 1 ; // Adding the length of the last consecutive identical characters to the variable sum1

  count4 = 1 ; // Initializing an integer counter count4 to one
  sum3 = 0 ; // Initializing an integer variable sum3 to zero
  bef3 = S3 [ 0 ] ; // Assigning the first character in the string S3 to the character variable bef3

  # The fourth for loop is used to find the length of the longest consecutive identical characters in the string S3
  for i in range ( 1 , N ) :
    if S3 [ i ] == bef3 : // If the current character in S3 is the same as the previous character
      count4 += 1 ; // Incrementing the counter count4
    else : # If the current character in S3 is different from the previous character
      sum3 += count4 - 1 ; // Adding the length of the previous consecutive identical characters to the variable sum3, subtracting one
      count4 = 1 ; // Resetting the counter count4 to one
      bef3 = S3 [ i ] ; // Assigning the current character in S3 to the character variable bef3

  sum3 += count4 - 1 ; // Adding the length of the last consecutive identical characters to the variable sum3

  print ( max ( sum1 , sum3 ) ) ; // Printing the maximum of sum1 and sum3

if __name__ == "__main__" :
  main ( ) ; # Calling the main function

