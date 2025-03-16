
public class Task4 {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;
        int A = sc.nextInt ( ), B = sc.nextInt ( ), n = sc.nextInt ( ) ;
        System.out.println ( task4 ( A, B, n ) ) ;
    }
    public static int task4 ( int A, int B, int n ) {
        for ( int X = - 1000 ; X < 1001 ; X ++ ) {
            if ( A * ( X ** n ) == B ) {
                return X ;
            }
        }
        return "No solution" ;
    }
}
