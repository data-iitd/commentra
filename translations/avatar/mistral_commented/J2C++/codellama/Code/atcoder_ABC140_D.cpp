
#include <iostream>
#include <string>

using namespace std ;

int main ( ) {
  int N , K ; // Declaring two integer variables N and K
  string S ; // Declaring a string variable S

  cin >> N >> K >> S ; // Reading the first integer from the standard input and assigning it to the variable N, reading the second integer from the standard input and assigning it to the variable K, and reading a string from the standard input and assigning it to the variable S

  char c1 [ N ] , c3 [ N ] ; // Declaring two character arrays c1 and c3

  for ( int i = 0 ; i < N ; i ++ ) { // The first for loop is used to process the character array c1
    c1 [ i ] = S [ i ] ; // Assigning the current character in the string S to the current character in the character array c1
  }

  for ( int i = 0 ; i < N ; i ++ ) { // The second for loop is used to process the character array c3
    c3 [ i ] = S [ N - i - 1 ] ; // Assigning the current character in the string S to the current character in the character array c3
  }

  bool flag1 = false ; // Initializing a boolean flag1 to false
  int count1 = 0 ; // Initializing an integer counter count1 to zero

  for ( int i = 0 ; i < N ; i ++ ) { // The third for loop is used to process the character array c1
    if ( flag1 && c1 [ i ] == 'R' ) { // If flag1 is true and the current character in c1 is 'R'
      flag1 = false ; // Setting flag1 to false
      count1 ++ ; // Incrementing the counter count1
    }
    if ( count1 == K ) { // If the counter count1 has reached the value K
      break ; // Exiting the for loop
    }
    if ( c1 [ i ] == 'L' ) { // If the current character in c1 is 'L'
      flag1 = true ; // Setting flag1 to true
    }
  }

  bool flag3 = false ; // Initializing a boolean flag3 to false
  int count3 = 0 ; // Initializing an integer counter count3 to zero

  for ( int i = 0 ; i < N ; i ++ ) { // The fourth for loop is used to process the character array c3
    if ( flag3 && c3 [ i ] == 'L' ) { // If flag3 is true and the current character in c3 is 'L'
      flag3 = false ; // Setting flag3 to false
      count3 ++ ; // Incrementing the counter count3
    }
    if ( count3 == K ) { // If the counter count3 has reached the value K
      break ; // Exiting the for loop
    }
    if ( c3 [ i ] == 'R' ) { // If the current character in c3 is 'R'
      flag3 = true ; // Setting flag3 to true
    }
  }

  string S1 = string ( c1 , N ) ; // Creating a new string object S1 from the character array c1
  string S3 = string ( c3 , N ) ; // Creating a new string object S3 from the character array c3

  int count2 = 1 ; // Initializing an integer counter count2 to one
  int sum1 = 0 ; // Initializing an integer variable sum1 to zero
  char bef1 = S1 [ 0 ] ; // Assigning the first character in the string S1 to the character variable bef1

  for ( int i = 1 ; i < N ; i ++ ) { // The fifth for loop is used to find the length of the longest consecutive identical characters in the string S1
    if ( S1 [ i ] == bef1 ) { // If the current character in S1 is the same as the previous character
      count2 ++ ; // Incrementing the counter count2
    } else { // If the current character in S1 is different from the previous character
      sum1 += count2 - 1 ; // Adding the length of the previous consecutive identical characters to the variable sum1, subtracting one
      count2 = 1 ; // Resetting the counter count2 to one
      bef1 = S1 [ i ] ; // Assigning the current character in S1 to the character variable bef1
    }
  }
  sum1 += count2 - 1 ; // Adding the length of the last consecutive identical characters to the variable sum1

  int count4 = 1 ; // Initializing an integer counter count4 to one
  int sum3 = 0 ; // Initializing an integer variable sum3 to zero
  char bef3 = S3 [ 0 ] ; // Assigning the first character in the string S3 to the character variable bef3

  for ( int i = 1 ; i < N ; i ++ ) { // The sixth for loop is used to find the length of the longest consecutive identical characters in the string S3
    if ( S3 [ i ] == bef3 ) { // If the current character in S3 is the same as the previous character
      count4 ++ ; // Incrementing the counter count4
    } else { // If the current character in S3 is different from the previous character
      sum3 += count4 - 1 ; // Adding the length of the previous consecutive identical characters to the variable sum3, subtracting one
      count4 = 1 ; // Resetting the counter count4 to one
      bef3 = S3 [ i ] ; // Assigning the current character in S3 to the character variable bef3
    }
  }
  sum3 += count4 - 1 ; // Adding the length of the last consecutive identical characters to the variable sum3

  cout << max ( sum1 , sum3 ) << endl ; // Printing the maximum of sum1 and sum3

  return 0 ; // Returning zero
}

