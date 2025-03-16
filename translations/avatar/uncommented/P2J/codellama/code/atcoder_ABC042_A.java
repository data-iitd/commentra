Scanner sc = new Scanner ( System.in );
int [] ABC = new int [ 3 ];
for ( int i = 0; i < 3; i++ ) {
    ABC [ i ] = sc.nextInt ( );
}
if ( Arrays.asList ( ABC ).contains ( 5 ) && Arrays.asList ( ABC ).contains ( 5 ) ) {
    if ( Arrays.stream ( ABC ).sum ( ) == 17 ) {
        System.out.println ( "YES" );
    } else {
        System.out.println ( "NO" );
    }
} else {
    System.out.println ( "NO" );
}
