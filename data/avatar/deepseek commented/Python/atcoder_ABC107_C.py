import sys
N , K = map ( int , input ( ).split ( ) )  # Reading N and K from input
lst = list ( map ( int , input ( ).split ( ) ) )  # Reading the list of integers
lst_p = [ ]  # List to store positive numbers
lst_m = [ ]  # List to store negative numbers

# Separating positive and negative numbers
for i in range ( N ) :
    if lst [ i ] == 0 :
        K -= 1  # Decrement K if the number is 0
    if lst [ i ] > 0 :
        lst_p += [ lst [ i ] ]  # Add positive numbers to lst_p
    elif lst [ i ] < 0 :
        lst_m += [ lst [ i ] ]  # Add negative numbers to lst_m

# Initialization of pointers and variables
p = 0  # Pointer for positive numbers
m = 0  # Pointer for negative numbers
x , y = 0 , len ( lst_m ) - 1  # Pointers for traversing lists
lastx = len ( lst_p )  # Last index of lst_p
lasty = len ( lst_m )  # Last index of lst_m

# Function to check the minimum possible value
def check ( k ) :
    ans = 10 ** 9  # Initialize answer with a large number
    for j in range ( 0 , k + 1 ) :
        if j > lastx or k - j > lasty :  # Check if indices are out of bounds
            pass
        else :
            if j == 0 :
                p = 0  # If no positive number is chosen, p is 0
            else :
                p = lst_p [ j - 1 ]  # Get the (j-1)th positive number
            if k - j == 0 :
                m = 0  # If no negative number is chosen, m is 0
            else :
                m = lst_m [ lasty - ( k - j ) ]  # Get the (lasty - (k - j))th negative number
            ans = min ( ans , 2 * p + abs ( m ) , p + 2 * abs ( m ) )  # Calculate the minimum value
    return ans

# Output the result of the check function with K as the argument
print ( check ( K ) )
