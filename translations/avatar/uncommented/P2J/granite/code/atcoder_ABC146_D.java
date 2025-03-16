
import java.util.*;
import java.io.*;
class atcoder_ABC146_D {
    static int bfs ( int v, int N, ArrayList < Integer > [] G, HashMap < String, Integer > E ) {
        int [] visited = new int [ N ] ;
        Queue < Integer > queue = new LinkedList < Integer > ( ) ;
        int K = - 1 ;
        int [] node2color = new int [ N ] ;
        queue.add ( v ) ;
        visited [ v ] = 1 ;
        while (! queue.isEmpty ( ) ) {
            int q = queue.poll ( ) ;
            int color = 0 ;
            for ( int nex : G [ q ] ) {
                if ( visited [ nex ]!= 0 ) {
                    continue;
                }
                visited [ nex ] = 1 ;
                color += 1 ;
                if ( color == node2color [ q ] ) {
                    color += 1 ;
                }
                node2color [ nex ] = color ;
                E.put ( ( Math. min ( q, nex ) ) + " " + ( Math. max ( q, nex ) ), color ) ;
                queue.add ( nex ) ;
            }
            K = Math. max ( K, color ) ;
        }
        return K ;
    }
    static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System. in ) ;
        int N = in.nextInt ( ) ;
        ArrayList < Integer > [] G = new ArrayList [ N ] ;
        for ( int i = 0 ; i < N ; i ++ ) {
            G [ i ] = new ArrayList < Integer > ( ) ;
        }
        HashMap < String, Integer > E = new HashMap < String, Integer > ( ) ;
        for ( int i = 0 ; i < N - 1 ; i ++ ) {
            int a = in.nextInt ( ) - 1 ;
            int b = in.nextInt ( ) - 1 ;
            G [ a ].add ( b ) ;
            G [ b ].add ( a ) ;
            E.put ( ( Math. min ( a, b ) ) + " " + ( Math. max ( a, b ) ), 0 ) ;
        }
        int K = bfs ( 0, N, G, E ) ;
        System. out. println ( K ) ;
        for ( Map. Entry < String, Integer > entry : E.entrySet ( ) ) {
            System. out. println ( entry. getValue ( ) ) ;
        }
    }
}
