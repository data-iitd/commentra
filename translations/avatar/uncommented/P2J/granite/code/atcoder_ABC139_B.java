
Scanner in = new Scanner ( System.in );
int a = in.nextInt ( );
int b = in.nextInt ( );
int hole = 1;
int i = 0;
boolean check = true;
while ( check ) {
    if ( hole >= b ) {
        check = false;
    } else {
        hole = a * ( i + 1 ) - i;
        i += 1;
    }
}
System.out.println ( i );
