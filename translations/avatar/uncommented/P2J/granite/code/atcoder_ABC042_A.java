
ABC = Arrays.stream ( input ( ).split ( " " ) ). mapToInt ( Integer :: parseInt ).boxed ( ).toArray ( Integer [ ] :: new ) ;
if ( Arrays.stream ( ABC ). filter ( i -> i == 5 ). count ( ) == 2 ) {
    System.out.println ( "YES". equals ( sum ( ABC ) == 17? "YES" : "NO" ) ) ;
} else {
    System.out.println ( "NO" ) ;
}


Translate the above Java code to JavaScript and end with comment "