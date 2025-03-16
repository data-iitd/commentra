
n , d = map ( int , input ( ).split ( ) )
# Taking input for two variables `n` and `d`

x = [ ]
m = 0
q = 0
# Initializing an empty list `x` and two integer variables `m` and `q` to 0

x = input ( ).split ( )
# Taking input for the list `x` as a string and splits it into individual elements

for i in range ( len ( x ) ) :
    x [ i ] = int ( x [ i ] )
# Converting the elements of the list `x` to integers

for a in range ( len ( x ) - 1 ) :
    if x [ a ] >= x [ a + 1 ] :
        q = int ( ( x [ a ] - x [ a + 1 ] ) / d + 1 )
        m = m + q
        x [ a + 1 ] = x [ a + 1 ] + q * d
# Checking if the current element is greater than or equal to the next element
# Calculating the number of steps `q` needed to make the current element less than the next element by at least `d`
# Updating the value of `m` by adding `q` to it
# Updating the next element in the list `x` by adding `q * d` to it

print ( m )
# Printing the value of `m`
