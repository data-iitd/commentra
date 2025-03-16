public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int [ ] sequence = new int [ n ];
        for ( int i = 0 ; i < n ; i++ ) {
            sequence [ i ] = sc.nextInt ( );
        }
        System.out.println ( nPairsWithCommonFX ( sequence ) );
    }
    public static int nPairsWithCommonFX ( int [ ] sequence ) {
        Map < Integer, List < Integer > > storage = new HashMap < > ( );
        List < Integer > FXs = new ArrayList < > ( );
        for ( int value : sequence ) {
            int y = f ( value );
            if (!storage.containsKey ( y ) ) {
                storage.put ( y, new ArrayList < > ( ) );
                FXs.add ( y );
            }
            storage.get ( y ).add ( value );
        }
        int ans = 0;
        for ( int y : FXs ) {
            ans += storage.get ( y ).size ( ) * storage.get ( y ).size ( );
        }
        for ( int y : FXs ) {
            ans -= storage.get ( y ).size ( );
        }
        return ans / 2;
    }
    public static int f ( int n ) {
        int y = 1;
        while ( n!= 1 ) {
            if ( n % 2!= 0 ) {
                y++;
            }
            n /= 2;
        }
        return y;
    }
}
