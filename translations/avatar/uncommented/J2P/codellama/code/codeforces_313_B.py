
import sys

def main ( ):
    br = sys.stdin
    pw = sys.stdout
    f = Fast ( )
    f.sol ( br , pw )
    pw.close ( )

class Fast:
    def sol ( self , br , pw ):
        st = br.readline ( ).split ( )
        s = st [ 0 ]
        cum = [ 0 ] * ( len ( s ) + 1 )
        cum [ 0 ] = cum [ len ( s ) ] = 0
        for i in range ( 1 , len ( s ) ):
            if s [ i ] == s [ i - 1 ]:
                cum [ i ] = cum [ i - 1 ] + 1
            else:
                cum [ i ] = cum [ i - 1 ]
        st = br.readline ( ).split ( )
        q = int ( st [ 0 ] )
        while q > 0:
            st = br.readline ( ).split ( )
            l = int ( st [ 0 ] )
            r = int ( st [ 1 ] ) - 1
            pw.write ( str ( cum [ r ] - cum [ l - 1 ] ) + '\n' )
            q -= 1

if __name__ == "__main__":
    main ( )

