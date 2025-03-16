import java.util.*;
import java.io.*;
import java.lang.*;

class Main {
    public static void main ( String [] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int k = sc.nextInt ( );
        int [] a = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            a [ i ] = sc.nextInt ( ) - 1;
        }
        int [] height_from_leaf = new int [ n ];
        int [] cut_count = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            height_from_leaf [ i ] = 0;
            cut_count [ i ] = 0;
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            for ( int j = 0 ; j < n ; j ++ ) {
                if ( a [ j ] == i ) {
                    height_from_leaf [ i ] = Math.max ( height_from_leaf [ i ] , height_from_leaf [ j ] + 1 );
                    cut_count [ i ] += cut_count [ j ];
                }
            }
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( height_from_leaf [ i ] == k ) {
                height_from_leaf [ i ] = 0;
                cut_count [ i ] += 1;
            }
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( a [ i ] == 0 ) {
                ans += cut_count [ i ];
            }
        }
        if ( a [ 0 ] != 1 ) {
            ans += 1;
        }
        System.out.println ( ans );
    }
}



Translate the above Java code to C++ and end with comment "