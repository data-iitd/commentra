import java.util.*;
import java.io.*;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int [ ] vis = new int [ n + 1 ];
        int ci = 0, cb = 0, cc = 0;
        ArrayList < Integer > [ ] g = new ArrayList < Integer > [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ )
            g [ i ] = new ArrayList < Integer > ( );
        for ( int i = 0 ; i < m ; i ++ ) {
            int u = sc.nextInt ( ), v = sc.nextInt ( );
            g [ u ].add ( v );
            g [ v ].add ( u );
        }
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( vis [ i ] == 0 ) {
                if ( g [ i ].size ( ) == 0 )
                    ci += 1;
                else {
                    if ( dfs ( i, 1, g, vis ) )
                        cb += 1;
                    else
                        cc += 1;
                }
            }
        }
        System.out.println ( ci * ci + 2 * ci * ( n - ci ) + cc * cc + 2 * cb * cc + 2 * cb * cb );
    }
    public static boolean dfs ( int x, int col, ArrayList < Integer > [ ] g, int [ ] vis ) {
        Stack < Integer > stk = new Stack < > ( );
        stk.push ( x );
        vis [ x ] = col;
        while (!stk.empty ( ) ) {
            int u = stk.pop ( );
            if ( vis [ u ]!= col )
                return false;
            for ( int i : g [ u ] ) {
                if ( vis [ i ] == 0 ) {
                    stk.push ( i );
                    vis [ i ] = 3 - col;
                } else if ( vis [ i ]!= 3 - col )
                    return false;
            }
        }
        return true;
    }
}

