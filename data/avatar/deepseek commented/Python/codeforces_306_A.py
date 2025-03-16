
n , m = map ( int , input ( ).split ( ) )  # Take two integers n and m as input
# These integers represent the total number of items n and the number of groups m

q = n // m  # Calculate the quotient, which is the number of items each group will have
r = n % m   # Calculate the remainder, which is the number of items that will be left over

a = [ q ] * m  # Initialize an array a of length m with each element set to q
# This represents the initial distribution of items among the groups

for i in range ( r ) :  # Loop for the number of remaining items r
    a [ i ] += 1  # Increment the corresponding element in the array a by 1
    # Ensuring that the remaining items are distributed evenly

for i in range ( m ) :  # Loop to print the elements of the array a
    print ( a [ i ] , end = ' ' )  # Print each element separated by a space

