
import sys

def main ( ) :
    t = int ( sys.stdin.readline ( ) )
    m = int ( sys.stdin.readline ( ) )
    memory = [ 0 ] * m
    allocIdx = 0

    for j in range ( t ) :
        command = sys.stdin.readline ( ).strip ( )
        if command == "alloc" :
            n = int ( sys.stdin.readline ( ) )
            len = 0
            canAlloc = False
            for i in range ( m ) :
                if memory [ i ] == 0 :
                    len += 1
                else :
                    len = 0
                if len == n :
                    canAlloc = True
                    len = i - n + 1
                    break
            if canAlloc :
                allocIdx += 1
                for i in range ( len, len + n ) :
                    memory [ i ] = allocIdx
                print ( allocIdx )
            else :
                print ( "NULL" )
        elif command == "erase" :
            x = int ( sys.stdin.readline ( ) )
            if x <= 0 :
                print ( "ILLEGAL_ERASE_ARGUMENT" )
                continue
            hasErased = False
            for i in range ( m ) :
                if memory [ i ] == x :
                    memory [ i ] = 0
                    hasErased = True
            if not hasErased :
                print ( "ILLEGAL_ERASE_ARGUMENT" )
        elif command == "defragment" :
            d = 0
            for i in range ( m ) :
                if memory [ i ] == 0 :
                    d += 1
            newSize = m - d
            newMemory = [ 0 ] * newSize
            k = 0
            for i in range ( m ) :
                if memory [ i ] != 0 :
                    newMemory [ k ] = memory [ i ]
                    k += 1
            memory = newMemory
        else :
            print ( "h" )

if __name__ == "__main__" :
    main ( )

