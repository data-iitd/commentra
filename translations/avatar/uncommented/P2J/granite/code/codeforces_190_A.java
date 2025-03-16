
Scanner in = new Scanner ( System.in );
int n = in.nextInt ( );
int m = in.nextInt ( );
if ( n < 1 ) {
    if ( m < 1 ) {
        System.out.println ( n + " " + m );
        System.exit ( 0 );
    }
    System.out.println ( "Impossible" );
    System.exit ( 0 );
}
if ( m > n ) {
    int min = m;
    int max = n + m - 1;
    System.out.println ( min + " " + max );
}
if ( m <= n ) {
    int min = n;
    int max = n + m - 1;
    if ( m == 0 ) {
        max = n;
    }
    System.out.println ( min + " " + max );
}
