
MOD = 998244353L
dp = [ [ 0 for i in range ( 3001 ) ] for j in range ( 3001 ) ]
def solve ( sc, pw ) :
    A = sc. nextInt ( )
    B = sc. nextInt ( )
    C = sc. nextInt ( )
    D = sc. nextInt ( )
    dp [ A ] [ B ] = 1
    for c in range ( A, C + 1 ) :
        for d in range ( B, D + 1 ) :
            if ( c == A and d == B ) :
                continue
            ans = 0
            if ( c > A ) :
                part = dp [ c - 1 ] [ d ]
                ans = ( part * d )
            if ( d > B ) :
                part = dp [ c ] [ d - 1 ]
                ans = ( ans + ( part * c ) )
            if ( c > A and d > B ) :
                ans = ( ans - ( dp [ c - 1 ] [ d - 1 ] * ( c - 1 ) * ( d - 1 ) ) )
            dp [ c ] [ d ] = ( ( ans % MOD ) + MOD ) % MOD
    pw. println ( dp [ C ] [ D ] )
if __name__ == "__main__" :
    sc = Scanner ( System.in )
    pw = PrintWriter ( System.out )
    solve ( sc, pw )
    pw. flush ( )
    pw. close ( )
    sc. close ( )
