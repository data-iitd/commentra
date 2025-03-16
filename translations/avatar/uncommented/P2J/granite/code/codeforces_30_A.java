
import java. util. * ;
class GFG {
    static String task4 ( int A, int B, int n ) {
        for ( int X = - 1000 ; X <= 1000 ; X ++ ) {
            if ( A * ( int ) Math. pow ( X, n ) == B ) {
                return Integer. toString ( X ) ;
            }
        }
        return "No solution" ;
    }
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System. in ) ;
        int A = sc. nextInt ( ) ;
        int B = sc. nextInt ( ) ;
        int n = sc. nextInt ( ) ;
        System. out. println ( task4 ( A, B, n ) ) ;
    }
}
