
N , M = map ( int , input ( ).split ( ) )
# Read the values of N and M
S = input ( )
# Read the string S
T = input ( )
# Read the string T
list_S = list ( S )
# Convert string S to a list of characters
list_T = list ( T )
# Convert string T to a list of characters
Number_i = [ i for i in range ( N ) ]
# Create a list of indices from 0 to N-1
Number_iMN = [ ]
for i in Number_i :
    Number_iMN.append ( i * M / N )
# Calculate a new list where each element is i * M / N
Number_j = [ j for j in range ( M ) ]
# Create a list of indices from 0 to M-1
Kaburi_j = list ( set ( Number_iMN ) & set ( Number_j ) )
# Find the intersection of Number_iMN and Number_j
Kaburi_i = [ ]
for j in Kaburi_j :
    Kaburi_i.append ( int ( j * N / M ) )
# Calculate Kaburi_i by converting each element of Kaburi_j to an integer and multiplying by N/M
counter = 0
Flag = 0
Kaburi_Size = len ( Kaburi_i )
# Initialize counter and flag
while counter <= Kaburi_Size - 1 :
    if list_S [ int ( Kaburi_i [ counter ] ) ] == list_T [ int ( Kaburi_j [ counter ] ) ] :
        pass
    else :
        Flag = 1
        break
    counter += 1
# Iterate through Kaburi_i to check if corresponding characters in list_S and list_T are the same
def gcd ( a , b ) :
    while b > 0 :
        a , b = b , a % b
    return a
# Define a function to calculate the greatest common divisor (GCD) of two numbers
if Flag == 1 :
    print ( - 1 )
else :
    print ( int ( N * M / gcd ( N , M ) ) )
# If the flag is 1, print -1. Otherwise, print the result of N*M divided by the GCD of N and M.

