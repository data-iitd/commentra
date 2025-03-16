
final int MOD = 100000007;
Scanner in = new Scanner ( System.in );
String l = in.nextLine ( );
int n = l.length ( );
int[][] dp = new int [ n + 1 ] [ 2 ];
dp [ 0 ] [ 0 ] = 1;
for ( int i = 0; i < n; i ++ ) {
    char c = l.charAt ( i );
    if ( c == '0' ) {
        dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ];
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
    } else {
        dp [ i + 1 ] [ 0 ] += dp [ i ] [ 0 ] * 2;
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 0 ];
        dp [ i + 1 ] [ 1 ] += dp [ i ] [ 1 ] * 3;
    }
    dp [ i + 1 ] [ 0 ] %= MOD;
    dp [ i + 1 ] [ 1 ] %= MOD;
}
System.out.println ( ( dp [ n ] [ 0 ] + dp [ n ] [ 1 ] ) % MOD );
