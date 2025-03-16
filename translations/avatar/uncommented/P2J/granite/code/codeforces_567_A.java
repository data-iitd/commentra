
Scanner in = new Scanner ( System.in ) ;
int inp = in.nextInt ( ) ;
ArrayList < Integer > lista = new ArrayList < Integer > ( ) ;
String [] input = in.next ( ).split ( " " ) ;
for ( int i = 0 ; i < input.length ; i ++ ) {
    lista.add ( Integer.parseInt ( input [ i ] ) ) ;
}
for ( int i = 0 ; i < lista.size ( ) ; i ++ ) {
    if ( i == 0 ) {
        System.out.print ( ( lista.get ( i + 1 ) - lista.get ( i ) ) + " " + ( lista.get ( lista.size ( ) - 1 ) - lista.get ( i ) ) ) ;
        continue ;
    }
    else if ( i == lista.size ( ) - 1 ) {
        System.out.print ( ( lista.get ( lista.size ( ) - 1 ) - lista.get ( lista.size ( ) - 2 ) ) + " " + ( lista.get ( lista.size ( ) - 1 ) - lista.get ( 0 ) ) ) ;
        continue ;
    }
    else if ( lista.get ( i ) - lista.get ( i - 1 ) > lista.get ( i + 1 ) - lista.get ( i ) ) {
        System.out.print ( ( lista.get ( i + 1 ) - lista.get ( i ) ) + " " ) ;
    }
    else {
        System.out.print ( ( lista.get ( i ) - lista.get ( i - 1 ) ) + " " ) ;
    }
    if ( lista.get ( lista.size ( ) - 1 ) - lista.get ( i ) > lista.get ( i ) - lista.get ( 0 ) ) {
        System.out.println ( ( lista.get ( lista.size ( ) - 1 ) - lista.get ( i ) ) ) ;
    }
    else {
        System.out.println ( ( lista.get ( i ) - lista.get ( 0 ) ) ) ;
    }
}
