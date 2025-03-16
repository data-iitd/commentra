public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;
        int x = sc.nextInt ( ), y = sc.nextInt ( ), a = sc.nextInt ( ), b = sc.nextInt ( ) ;
        int lcm = L ( x, y ) ;
        System.out.println ( b / lcm - ( a - 1 ) / lcm ) ;
    }
    public static int L ( int a, int b ) {
        while ( a % b!= 0 ) {
            int temp = a ;
            a = b ;
            b = temp % b ;
        }
        return a * b / b ;
    }
}
