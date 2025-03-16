import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int [ ] vis = new int [ n + 1 ];
        int ci = 0, cb = 0, cc = 0;
        ArrayList < Integer > [ ] g = new ArrayList < > [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ )
            g.add ( new ArrayList < > ( ) );
        for ( int i = 0 ; i < m ; i ++ ) {
            int u = sc.nextInt ( );
            int v = sc.nextInt ( );
            g.get ( u ).add ( v );
            g.get ( v ).add ( u );
        }
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( vis [ i ] == 0 ) {
                if ( g.get ( i ).size ( ) == 0 )
                    ci += 1;
                else {
                    boolean flag = true;
                    for ( int j : g.get ( i ) ) {
                        if ( vis [ j ] == 0 ) {
                            flag &= dfs ( j, 1 );
                        } else {
                            flag &= ( vis [ j ] == 1 );
                        }
                    }
                    if ( flag )
                        cb += 1;
                    else
                        cc += 1;
                }
            }
        }
        System.out.println ( ci * ci + 2 * ci * ( n - ci ) + cc * cc + 2 * cb * cc + 2 * cb * cb );
    }
    public static boolean dfs ( int u, int col ) {
        boolean flag = true;
        vis [ u ] = col;
        for ( int v : g.get ( u ) ) {
            if ( vis [ v ] == 0 ) {
                flag &= dfs ( v, 3 - col );
            } else {
                flag &= ( vis [ v ] == 3 - col );
            }
        }
        return flag;
    }
}
