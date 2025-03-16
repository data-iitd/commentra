n, m = map ( int, input ( ).split ( ) )
c = new HashSet<> ( ) ;
for ( int i = 0 ; i < n ; i ++ ) {
    c.add ( s.indexOf ( "S" ) - s.indexOf ( "G" ) ) ;
}
System.out.println ( c.contains ( - 1 )? - 1 : c.size ( ) ) ;

