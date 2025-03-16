
import sys

def gi ( ) :
    return int ( sys.stdin.readline ( ) . strip ( ) )

def gs ( ) :
    return sys.stdin.readline ( ) . strip ( )

def gl ( ) :
    return int ( sys.stdin.readline ( ) . strip ( ) )

def gd ( ) :
    return float ( sys.stdin.readline ( ) . strip ( ) )

N = gi ( )

i = 357
c = 0

while i <= N :
    s = str ( i )

    if "3" in s and "5" in s and "7" in s :
        c += 1

    f = False

    for j in range ( len ( s ) ) :
        a = s [ - j - 1 ]

        if f :
            sb.append ( a )
        else :
            if a == "3" :
                sb.append ( "5" )
                f = True
            elif a == "5" :
                sb.append ( "7" )
                f = True
            else :
                sb.append ( "3" )
                f = True

    if not f :
        sb.append ( "3" )

    sb2 = sb [ :: - 1 ]
    i = int ( sb2 )

print ( c )

