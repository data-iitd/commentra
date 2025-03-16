import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
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
                int u = aaa [ i ];
                if ( u!= -1 ) {
                    links [ u ].add ( i );
                }
            }
            int [ ] dp = new int [ n ];
            Arrays.fill ( dp, -1 );
            int ans = 0;
            int [ ] stack = new int [ n ];
            int top = 0;
            stack [ top ] = 0;
            while ( top >= 0 ) {
                int v = stack [ top -- ];
                if ( dp [ v ]!= -1 ) {
                    continue;
                }
                int height_from_leaf = 0;
                int cut_count = 0;
                for ( int u : links [ v ] ) {
                    if ( u == 0 ) {
                        continue;
                    }
                    int hgt = dp [ u ];
                    if ( hgt == -1 ) {
                        stack [ ++ top ] = u;
                    }
                    hgt = Math.max ( hgt, dp [ u ] );
                    height_from_leaf = Math.max ( height_from_leaf, hgt );
                    cut_count += dp [ u ] + 1;
                }
                height_from_leaf += 1;
                if ( v!= 0 && height_from_leaf == k ) {
                    height_from_leaf = 0;
                    cut_count += 1;
                }
                dp [ v ] = height_from_leaf;
                ans += cut_count;
            }
            if ( aaa [ 0 ]!= 1 ) {
                ans += 1;
            }
            System.out.println ( ans );
        } catch ( Exception e ) {
            e.printStackTrace ( );
        }
    }
}
