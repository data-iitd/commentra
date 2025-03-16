public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int k = sc.nextInt ( );
        int [ ] elems = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            elems [ i ] = sc.nextInt ( );
        }
        boolean allSame = true;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( elems [ i ]!= elems [ 0 ] ) {
                allSame = false;
                break;
            }
        }
        if ( allSame ) {
            System.out.println ( 0 );
            return;
        }
        if ( k == 1 ) {
            System.out.println ( - 1 );
            return;
        }
        if (! allSame ) {
            for ( int i = k - 1 ; i < n ; i ++ ) {
                if ( elems [ i ]!= elems [ i - 1 ] ) {
                    System.out.println ( - 1 );
                    return;
                }
            }
        }
        int target = elems [ n - 1 ];
        int [ ] toDelete = new int [ k - 1 ];
        for ( int i = 0 ; i < k - 1 ; i ++ ) {
            toDelete [ i ] = elems [ i ];
        }
        while ( toDelete.length > 0 && toDelete [ toDelete.length - 1 ] == target ) {
            toDelete = Arrays.copyOf ( toDelete, toDelete.length - 1 );
        }
        System.out.println ( toDelete.length );
    }
}
