#include <bits/stdc++.h>
using namespace std;

class Main {
public:
    static void main ( string [ ] args ) {
        FastReader in = new FastReader ( ) ;
        int n = in.nextInt ( ) ;
        set < int > left ;
        for ( int i = 0 ; i < n ; i ++ ) {
            left.insert ( i ) ;
        }
        int q = in.nextInt ( ) ;
        while ( q -- > 0 ) {
            int l = in.nextInt ( ) - 1 ;
            int r = in.nextInt ( ) - 1 ;
            int win = in.nextInt ( ) ;
            while ( left.upper_bound ( l )!= left.end ( ) && * ( left.upper_bound ( l ) ) <= r ) {
                int curr = * ( left.upper_bound ( l ) ) ;
                left.erase ( left.upper_bound ( l ) ) ;
                answer [ curr ] = win ;
            }
            answer [ win - 1 ] = 0 ;
            left.insert ( win - 1 ) ;
        }
        string ans = "" ;
        for ( int i = 0 ; i < n ; i ++ ) {
            ans += to_string ( answer [ i ] ) ;
        }
        cout << ans << endl ;
    }
} ;

class FastReader {
public:
    string [ ] st ;
    BufferedReader br ;
    public FastReader ( ) {
        br = new BufferedReader ( new InputStreamReader ( System.in ) ) ;
    }
    string next ( ) {
        while ( st == null || st [ st.length - 1 ] == null ) {
            try {
                st = br.readLine ( ).split ( " " ) ;
            } catch ( IOException e ) {
                e.printStackTrace ( ) ;
            }
        }
        return st [ st.length - 1 ] ;
    }
    int nextInt ( ) {
        return Integer.parseInt ( next ( ) ) ;
    }
    long nextLong ( ) {
        return Long.parseLong ( next ( ) ) ;
    }
    double nextDouble ( ) {
        return Double.parseDouble ( next ( ) ) ;
    }
    String nextLine ( ) {
        String s = "" ;
        while ( st == null || st.length == 0 || st [ st.length - 1 ] == null ) {
            try {
                s = br.readLine ( ) ;
            } catch ( IOException e ) {
                e.printStackTrace ( ) ;
            }
            st = s.split ( " " ) ;
        }
        return s ;
    }
} ;

