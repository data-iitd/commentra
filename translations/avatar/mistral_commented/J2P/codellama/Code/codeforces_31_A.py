
import sys

n = int ( input ( ) )

f = 0
a = [ ]

for i in range ( n ) :
    a.append ( int ( input ( ) ) )

k = 0
j = 0
i = 0

for k in range ( n ) :
    t = a [ k ]

    for i in range ( n ) :
        if i != k :
            for j in range ( n - 1 ) :
                if i != j and t == ( a [ i ] + a [ j ] ) :
                    f = 1
                    break
                if f == 1 :
                    break
            if f == 1 :
                break

if f == 0 :
    print ( "-1" )
else :
    print ( k + 1 , j + 1 , i + 1 )

