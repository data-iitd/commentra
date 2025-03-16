
import sys ;                             # Importing the sys module

Q = int ( input ( ) ) ;              # Reading the first integer value Q from the standard input
H = int ( input ( ) ) ;              # Reading the second integer value H from the standard input
S = int ( input ( ) ) ;              # Reading the third integer value S from the standard input
D = int ( input ( ) ) ;              # Reading the fourth integer value D from the standard input
N = int ( input ( ) ) ;              # Reading the fifth integer value N from the standard input

onePrice = min ( min ( Q * 4, H * 2 ), S ) ; # Calculating the minimum price per item among Q*4, H*2, and S

if ( ( float ) onePrice <= ( float ) D / 2 ) : # Checking if the minimum price per item is less than or equal to half of the deposit amount
    print ( N * onePrice ) ;                  # If true, printing the result as the product of N and the minimum price per item
else :                                           # If false, the following block is executed
    print ( ( N // 2 ) * D + ( N % 2 ) * onePrice ) ; # Calculating and printing the result as the sum of half of N multiplied by the deposit amount and the remaining N (if any) multiplied by the minimum price per item

