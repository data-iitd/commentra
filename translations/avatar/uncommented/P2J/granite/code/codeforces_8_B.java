
Scanner in = new Scanner ( System. in ) ;
String record_of_movements = in. next ( ) ;
int x = 0, y = 0 ;
Map < String, String > d_movement = new HashMap < > ( ) ;
d_movement. put ( "L", "0,-1" ) ;
d_movement. put ( "R", "0,1" ) ;
d_movement. put ( "U", "1,0" ) ;
d_movement. put ( "D", "-1,0" ) ;
Map < String, String > d = new HashMap < > ( ) ;
boolean bug = false ;
for ( int i = 0 ; i < record_of_movements. length ( ) ; i ++ ) {
    String temp = x + "," + y ;
    String [] xy = d_movement. get ( record_of_movements. substring ( i, i + 1 ) ). split ( "," ) ;
    x += Integer. parseInt ( xy [ 0 ] ) ;
    y += Integer. parseInt ( xy [ 1 ] ) ;
    if (! d. containsKey ( x + "," + y ) ) {
        for ( String step : d_movement. keySet ( ) ) {
            String [] xy_ = d_movement. get ( step ). split ( "," ) ;
            if ( ( x + Integer. parseInt ( xy_ [ 0 ] ) ) + "," + ( y + Integer. parseInt ( xy_ [ 1 ] ) )!= temp && d. containsKey ( ( x + Integer. parseInt ( xy_ [ 0 ] ) ) + "," + ( y + Integer. parseInt ( xy_ [ 1 ] ) ) ) {
                bug = true ;
                break ;
            }
        }
    } else {
        bug = true ;
    }
    if ( bug ) {
        break ;
    }
    d. put ( x + "," + y, "" ) ;
}
if ( bug ) {
    System. out. println ( "BUG" ) ;
} else {
    System. out. println ( "OK" ) ;
}
