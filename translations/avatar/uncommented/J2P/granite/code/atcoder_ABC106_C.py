
str = input ( )
c = list ( str )
k = int ( input ( ) )
n = len ( str )
for i in range ( k ) :
if ( c [ i ] == '1' ) :
if ( i == k - 1 ) :
print ( 1 )
return
else :
print ( c [ i ] )
return
