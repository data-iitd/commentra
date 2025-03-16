import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        String [ ] arr = new String [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            arr [ i ] = sc.next ( );
        }
        String s = sc.next ( );
        char c1 = sc.next ( ).charAt ( 0 );
        char c2 = c1 == 'a'? 'b' : 'a';
        char [ ] arr2 = new char [ s.length ( ) ];
        for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
            arr2 [ i ] = s.charAt ( i );
        }
        for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
            if ( arr2 [ i ] == c1 ) {
                arr2 [ i ] = c2;
            }
        }
        for ( char c : arr2 ) {
            System.out.print ( c );
        }
        System.out.println ( );
    }
}
