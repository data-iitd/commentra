
Scanner in = new Scanner ( System.in );
String soz = in.nextLine ( );
int [] a = new int [ soz.length ( ) + 1 ];
for ( int i = 1 ; i < soz.length ( ) ; i ++ ) {
    a [ i ] = a [ i - 1 ];
    if ( soz.charAt ( i - 1 ) == soz.charAt ( i ) ) {
        a [ i ] += 1;
    }
}
int n = in.nextInt ( );
int [] arr = new int [ n ];
for ( int i = 0 ; i < n ; i ++ ) {
    int m = in.nextInt ( );
    int l = in.nextInt ( );
    arr [ i ] = a [ l - 1 ] - a [ m - 1 ];
}
for ( int i = 0 ; i < n ; i ++ ) {
    System.out.println ( arr [ i ] );
}
