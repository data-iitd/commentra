
import sys

def cout ( str ) :
    print ( str )

def main ( ) :
    cin = sys.stdin.readline
    n = int ( cin ( ) )
    str = cin ( ).strip ( )
    a = str [ : n // 2 ]
    if str == a + a :
        cout ( "Yes" )
    else :
        cout ( "No" )

if __name__ == "__main__" :
    main ( )

