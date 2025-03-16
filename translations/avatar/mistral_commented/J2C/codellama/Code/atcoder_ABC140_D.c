
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
  int N ; // Declaring an integer variable N
  int K ; // Declaring an integer variable K
  char S [ 1000000 ] ; // Declaring a character array S

  scanf ( "%d %d %s" , &N , &K , S ) ; // Reading the first integer from the standard input and assigning it to the variable N, reading the second integer from the standard input and assigning it to the variable K, reading a string from the standard input and assigning it to the variable S

  char c1 [ 1000000 ] ; // Declaring a character array c1
  char c3 [ 1000000 ] ; // Declaring a character array c3

  int i = 0 ; // Declaring an integer variable i and initializing it to zero
  int j = 0 ; // Declaring an integer variable j and initializing it to zero

  // The first for loop is used to process the character array c1
  for ( i = 0 ; i < N ; i ++ ) {
    if ( i > 0 && S [ i ] == 'R' && S [ i - 1 ] == 'L' ) { // If the current character in S is 'R', the previous character is 'L', and the current character is not the first character in S
      c1 [ j ] = 'R' ; // Assigning the current character in S to the character array c1
      j ++ ; // Incrementing the counter j
    }
  }

  // The second for loop is used to process the character array c3
  for ( i = 0 ; i < N ; i ++ ) {
    if ( i > 0 && S [ i ] == 'L' && S [ i - 1 ] == 'R' ) { // If the current character in S is 'L', the previous character is 'R', and the current character is not the first character in S
      c3 [ j ] = 'L' ; // Assigning the current character in S to the character array c3
      j ++ ; // Incrementing the counter j
    }
  }

  c1 [ j ] = '\0' ; // Assigning the null character to the last element of the character array c1
  c3 [ j ] = '\0' ; // Assigning the null character to the last element of the character array c3

  int count1 = 0 ; // Declaring an integer variable count1 and initializing it to zero
  int count3 = 0 ; // Declaring an integer variable count3 and initializing it to zero

  // The third for loop is used to find the length of the longest consecutive identical characters in the string S
  for ( i = 0 ; i < N ; i ++ ) {
    if ( S [ i ] == S [ i + 1 ] ) { // If the current character in S is the same as the next character
      count1 ++ ; // Incrementing the counter count1
    } else { // If the current character in S is different from the next character
      count1 = 0 ; // Resetting the counter count1 to zero
    }
    if ( count1 == K ) { // If the counter count1 has reached the value K
      break ; // Exiting the for loop
    }
  }

  // The fourth for loop is used to find the length of the longest consecutive identical characters in the string S
  for ( i = 0 ; i < N ; i ++ ) {
    if ( S [ i ] == S [ i + 1 ] ) { // If the current character in S is the same as the next character
      count3 ++ ; // Incrementing the counter count3
    } else { // If the current character in S is different from the next character
      count3 = 0 ; // Resetting the counter count3 to zero
    }
    if ( count3 == K ) { // If the counter count3 has reached the value K
      break ; // Exiting the for loop
    }
  }

  printf ( "%d\n" , count1 > count3 ? count1 : count3 ) ; // Printing the maximum of count1 and count3

  return 0 ; // Returning zero
}

