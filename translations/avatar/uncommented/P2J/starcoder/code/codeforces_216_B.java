import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int [ ] g = new int [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ ) g [ i ] = new int [ ] { };
        for ( int i = 0 ; i < m ; i ++ ) {
            int a = sc.nextInt ( );
            int b = sc.nextInt ( );
            g [ a ] [ g [ a ].length ] = b;
            g [ b ] [ g [ b ].length ] = a;
        }
        int ans = 0;
        for ( int i = 1 ; i <= n ; i ++ ) {
            boolean [ ] seen = new boolean [ n + 1 ];
            if (!dfs ( g, seen, i ) ) ans ++;
        }
        if ( ( n - ans ) % 2 == 1 ) ans ++;
        System.out.println ( ans );
    }
    public static boolean dfs ( int [ ] g, boolean [ ] seen, int i ) {
        if ( seen [ i ] ) return false;
        seen [ i ] = true;
        int nodes = 1;
        int edges = g [ i ].length;
        for ( int j : g [ i ] ) {
            int x = dfs ( g, seen, j );
            nodes += x;
            edges += x;
        }
        return nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges;
    }
}
