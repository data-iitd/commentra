
String LUCKY = "abcd";
int n = Integer.parseInt ( input.nextLine ( ) );
String s = "";
for ( int i = 0; i < n; i ++ ) {
    s += LUCKY.charAt ( i % 4 );
}
System.out.println ( s );
