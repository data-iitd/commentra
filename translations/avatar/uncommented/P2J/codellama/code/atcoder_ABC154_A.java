import java.util.Scanner;
public class Main {
    public static void solve ( String S , String T , int A , int B , String U ) {
        if ( S.equals ( U ) ) {
            A -= 1;
        }
        if ( T.equals ( U ) ) {
            B -= 1;
        }
        System.out.println ( A + " " + B );
        return;
    }
    public static void main ( String[] args ) {
        Scanner sc = new Scanner ( System.in );
        String S = sc.next ( );
        String T = sc.next ( );
        int A = sc.nextInt ( );
        int B = sc.nextInt ( );
        String U = sc.next ( );
        solve ( S , T , A , B , U );
    }
}
