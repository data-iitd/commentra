
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 

// FastReader class to read input efficiently
class FastReader { 
    public: 
        FastReader ( ) { 
            br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        } 
        String next ( ) { 
            while ( st == null || ! st.hasMoreElements ( ) ) { 
                try { 
                    st = new StringTokenizer ( br.readLine ( ) ) ; 
                } catch ( IOException e ) { 
                    e.printStackTrace ( ) ; 
                } 
            } 
            return st.nextToken ( ) ; 
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
            String str = "" ; 
            try { 
                str = br.readLine ( ) ; 
            } catch ( Exception e ) { 
                e.printStackTrace ( ) ; 
            } 
            return str ; 
        } 
    } 

// Function to calculate x^y mod mod using efficient exponentiation by squaring
int modPower ( int x , int y , int mod ) { 
    int res = 1 ; 
    x %= mod ; 
    if ( x == 0 ) return 0 ; 
    while ( y > 0 ) { 
        if ( y % 2 == 1 ) { 
            res = ( res * x ) % mod ; 
        } 
        y = y >> 1 ; 
        x = ( x * x ) % mod ; 
    } 
    return res ; 
} 

// Generic pair class to hold two elements of type T1 and T2
template < class T1 , class T2 > 
class pair { 
    public: 
        T1 first ; 
        T2 second ; 
        pair ( T1 first , T2 second ) { 
            this.first = first ; 
            this.second = second ; 
        } 
} 

// Main function to read input, calculate the maximum product, and print the result
int main ( ) { 
    FastReader in = new FastReader ( ) ; 
    long [ ] a = new long [ 4 ] ; 
    for ( int i = 0 ; i < 4 ; i ++ ) 
        a [ i ] = in.nextLong ( ) ; 
    cout << max ( a [ 0 ] * a [ 2 ] , max ( a [ 1 ] * a [ 3 ] , max ( a [ 0 ] * a [ 3 ] , a [ 1 ] * a [ 2 ] ) ) ) << endl ; 
    return 0 ; 
} 

