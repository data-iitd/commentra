import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int s = sc.nextInt ( );
        int f = sc.nextInt ( );
        if ( s < f ) {
            int d = 1;
            char c = 'R';
        } else {
            int d = - 1;
            char c = 'L';
        }
        int i = 1;
        int j = s;
        int t = sc.nextInt ( );
        int l = sc.nextInt ( );
        int r = sc.nextInt ( );
        int k = 1;
        String res = "";
        while ( j!= f ) {
            if ( i > t && k < m ) {
                t = sc.nextInt ( );
                l = sc.nextInt ( );
                r = sc.nextInt ( );
                k += 1;
            }
            if ( i == t && ( l <= j && j <= r || l <= j + d && j + d <= r ) ) {
                res += 'X';
            } else {
                res += c;
                j += d;
            }
            i += 1;
        }
        System.out.println ( res );
    }
}
