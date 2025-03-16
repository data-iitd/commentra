
import sys
import heapq

def main ( ):
    t = int ( sys.stdin.readline ( ) )
    pqmax = [ ]
    pqmin = [ ]
    sumMin = 0
    sumMax = 0
    sumb = 0
    min = 0

    for i in range ( t ):
        s = sys.stdin.readline ( ).split ( )

        if s [ 0 ] == '2':
            ans = min
            ans *= len ( pqmin )
            ans -= sumMin
            ans1 = min
            ans1 = sumMax - ans1
            print ( min , ans + ans1 + sumb )
        else:
            in = int ( s [ 1 ] )
            sumb += int ( s [ 2 ] )

            if in > min:
                heapq.heappush ( pqmax , in )
                sumMax += in
            else:
                heapq.heappush ( pqmin , in )
                sumMin += in

            if len ( pqmin ) > len ( pqmax ):
                sumMax += pqmin [ 0 ]
                sumMin -= pqmin [ 0 ]
                heapq.heappush ( pqmax , heapq.heappop ( pqmin ) )
            elif len ( pqmin ) < len ( pqmax ):
                sumMax -= pqmax [ 0 ]
                sumMin += pqmax [ 0 ]
                heapq.heappush ( pqmin , heapq.heappop ( pqmax ) )

            min = pqmin [ 0 ]

main ( )

