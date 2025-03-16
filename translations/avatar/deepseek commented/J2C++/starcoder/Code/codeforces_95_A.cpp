#include <bits/stdc++.h>
using namespace std;

class Main {
public:
    // Constructor to initialize the superclass with System.out and auto-flush enabled
    Main ( ) {
        super ( System.out, true ) ;
    }

    // Scanner object to read input from System.in
    Scanner sc = new Scanner ( System.in ) ;

    // Main method which is overridden and calls another main method within the class
    public static void main ( String [ ] $ ) {
        Main o = new Main ( ) ;
        o.main ( ) ;
        o.flush ( ) ;
    }

    // Compares two character arrays up to a specified length, ignoring case
    int compare ( char [ ] aa, int i, char [ ] bb, int j, int m ) {
        while ( m -- > 0 ) {
            char a = Character.toUpperCase ( aa [ i ] ) ;
            char b = Character.toUpperCase ( bb [ j ] ) ;
            if ( a!= b ) return a - b ;
            i ++ ;
            j ++ ;
        }
        return 0 ;
    }

    // Main logic of the program
    void main ( ) {
        // Reading the number of strings and the array of strings
        int n = sc.nextInt ( ) ;
        char [ ] [ ] ss = new char [ n ] [ ] ;
        for ( int i = 0 ; i < n ; i ++ )
            ss [ i ] = sc.next ( ).toCharArray ( ) ;

        // Reading the pattern array and the target character
        char [ ] cc = sc.next ( ).toCharArray ( ) ;
        int m = cc.length ;
        char c = sc.next ( ).charAt ( 0 ) ;
        char c_ = Character.toUpperCase ( c ) ;
        char a = c == 'a'? 'b' : 'a' ;
        char a_ = Character.toUpperCase ( a ) ;

        // Array to mark positions in cc that match any string in ss
        bool [ ] lucky = new bool [ m ] ;

        // Finding lucky positions and updating characters based on the target character c
        for ( int j = 0 ; j < m ; j ++ )
            for ( int i = 0 ; i < n ; i ++ ) {
                int l = ss [ i ].length ;
                if ( m - j >= l && compare ( cc, j, ss [ i ], 0, l ) == 0 )
                    for ( int h = 0 ; h < l ; h ++ )
                        lucky [ j + h ] = true ;
            }

        // Updating characters in cc based on the lucky positions and target character c
        for ( int j = 0 ; j < m ; j ++ )
            if ( lucky [ j ] ) {
                if ( Character.toLowerCase ( cc [ j ] ) == c )
                    cc [ j ] = Character.isUpperCase ( cc [ j ] )? a_ : a ;
                else
                    cc [ j ] = Character.isUpperCase ( cc [ j ] )? c_ : c ;
            }

        // Printing the modified cc array
        println ( cc ) ;
    }
}

