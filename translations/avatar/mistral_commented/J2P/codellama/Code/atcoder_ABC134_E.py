
import sys

n = int ( input ( ) )

map = { }

for i in range ( n ) :
    num = int ( input ( ) )

    if num not in map :
        map [ num ] = 1
    else :
        if map [ num ] == 1 :
            del map [ num ]
        else :
            map [ num ] -= 1

        map [ num ] += 1

ans = 0

for key in map :
    ans += map [ key ]

print ( ans )

