
import sys

def main ( ):
    N = int ( sys.stdin.readline ( ) )
    L = list ( )

    for i in range ( N ):
        L.append ( int ( sys.stdin.readline ( ) ) )

    L.sort ( )

    count = 0

    for i in range ( N ):
        for j in range ( i + 1 , N ):
            a = L [ i ]
            b = L [ j ]
            res = find ( L , j + 1 , a + b )
            count += res

    print ( count )

def find ( L , from , target ):
    low = from
    upp = len ( L ) - 1
    mid = 0

    if upp - low < 0:
        return 0
    elif L [ from ] >= target:
        return 0
    elif L [ upp ] < target:
        return upp - low + 1

    while upp - low > 1:
        mid = ( upp - low + 1 ) % 2 == 0 and ( low + upp ) / 2 + 1 or ( low + upp ) / 2

        if L [ mid ] >= target:
            upp = mid
        else:
            low = mid

    return low - from + 1

if __name__ == "__main__":
    main ( )

