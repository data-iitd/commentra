
x , y , z , k = [ int ( _ ) for _ in input ( ).split ( ) ]
# Taking four integer inputs: x, y, z, and k

a = [ int ( _ ) for _ in input ( ).split ( ) ]
# Reading list a of integers

b = [ int ( _ ) for _ in input ( ).split ( ) ]
# Reading list b of integers

c = [ int ( _ ) for _ in input ( ).split ( ) ]
# Reading list c of integers

ab = [ ]
# Initializing an empty list ab to store sums of elements from a and b

for i in range ( x ) :
    for j in range ( y ) :
        ab.append ( a [ i ] + b [ j ] )
# Populating list ab with sums of elements from a and b

ab.sort ( reverse = True )
# Sorting list ab in descending order

abc = [ ]
# Initializing an empty list abc to store sums of elements from ab and c

for i in range ( min ( k , x * y ) ) :
    for j in range ( z ) :
        abc.append ( ab [ i ] + c [ j ] )
# Populating list abc with sums of elements from ab and c, limited by k

abc.sort ( reverse = True )
# Sorting list abc in descending order

for i in range ( k ) :
    print ( abc [ i ] )
# Printing the first k elements of abc in descending order
