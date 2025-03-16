s = str ( input ( ) )
my_str = ""
for ( int i = 0 ; i < s.length ( ) ; i++ ) {
    if ( s.charAt ( i ) == '0' || s.charAt ( i ) == '1' ) {
        my_str += s.charAt ( i ) ;
    } else if ( s.charAt ( i ) == 'B' && my_str.length ( )!= 0 ) {
        my_str = my_str.substring ( 0, my_str.length ( ) - 1 ) ;
    }
}
System.out.println ( my_str )

