import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int M = sc.nextInt ( );
        int [ ] [ ] edge = new int [ N ] [ N ];
        for ( int i = 0 ; i < M ; i ++ ) {
            int X = sc.nextInt ( ) - 1;
            int Y = sc.nextInt ( ) - 1;
            int Z = sc.nextInt ( );
            edge [ X ] [ Y ] = Z;
            edge [ Y ] [ X ] = Z;
        }
        int ans = 0;
        boolean [ ] used = new boolean [ N ];
        for ( int i = 0 ; i < N ; i ++ ) {
            if (!used [ i ] ) {
                ans += 1;
                Queue < Integer > queue = new LinkedList < > ( );
                queue.add ( i );
                while (!queue.isEmpty ( ) ) {
                    int node = queue.poll ( );
                    used [ node ] = true;
                    for ( int nextnode = 0 ; nextnode < N ; nextnode ++ ) {
                        if (!used [ nextnode ] && edge [ node ] [ nextnode ] > 0 ) {
                            queue.add ( nextnode );
                        }
                    }
                }
            }
        }
        System.out.println ( ans );
    }
}
