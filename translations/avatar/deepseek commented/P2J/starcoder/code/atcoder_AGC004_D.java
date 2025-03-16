
import java.util.*;
import java.io.*;

public class Main {
    public static void main ( String [ ] args ) {
        new Main ( ).run ( );
    }
    public void run ( ) {
        try {
            BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
            int n = Integer.parseInt ( br.readLine ( ) );
            int k = Integer.parseInt ( br.readLine ( ) );
            int [ ] aaa = new int [ n ];
            for ( int i = 0 ; i < n ; i ++ ) {
                aaa [ i ] = Integer.parseInt ( br.readLine ( ) ) - 1;
            }
            int [ ] links = new int [ n ];
            for ( int i = 0 ; i < n ; i ++ ) {
                links [ i ] = new TreeSet < > ( );
            }
            for ( int i = 0 ; i < n ; i ++ ) {
                for ( int j = 0 ; j < n ; j ++ ) {
                    if ( aaa [ i ] == j ) {
                        continue;
                    }
                    links [ aaa [ i ] ].add ( j );
                }
            }
            int [ ] ans = new int [ 2 ];
            dfs ( links, n, k, 0, 0, ans );
            if ( aaa [ 0 ]!= 1 ) {
                ans [ 1 ] += 1;
            }
            System.out.println ( ans [ 1 ] );
        } catch ( Exception e ) {
            return;
        }
    }
    public void dfs ( int [ ] links, int n, int k, int v, int p, int [ ] ans ) {
        int heightFromLeaf = 0;
        int cutCount = 0;
        for ( int u : links [ v ] ) {
            if ( u == 0 ) {
                continue;
            }
            int [ ] hgtCut = new int [ 2 ];
            dfs ( links, n, k, u, v, hgtCut );
            heightFromLeaf = Math.max ( heightFromLeaf, hgtCut [ 0 ] );
            cutCount += hgtCut [ 1 ];
        }
        heightFromLeaf += 1;
        if ( p!= 0 && heightFromLeaf == k ) {
            heightFromLeaf = 0;
            cutCount += 1;
        }
        ans [ 0 ] = Math.max ( ans [ 0 ], heightFromLeaf );
        ans [ 1 ] += cutCount;
    }
}

