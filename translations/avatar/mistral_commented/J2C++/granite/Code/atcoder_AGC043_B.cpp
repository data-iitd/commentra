

#include <bits/stdc++.h>

using namespace std;

class Main {
public:
    int cal ( string s, char c ) {
        int n = s.length() ;
        int m = n - 1 ;
        int ans = 0 ;
        
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( s[i] == c && (m & i) == i ) {
                ans ^= 1 ;
            }
        }
        
        return ans ;
    }
    
    void solve ( ) {
        int n = sc.nextInt() ;
        
        for ( int testCase = 1 ; testCase <= n ; testCase++ ) {
            int num = sc.nextInt() ;
            string s = sc.next() ;
            
            stringstream ss ;
            for ( int i = 1 ; i < num ; i ++ ) {
                ss << abs(s[i] - s[i - 1]) ;
            }
            
            if ( num == 2 ) {
                cout << ss.str()[0] << endl ;
                continue ;
            }
            
            s = ss.str() ;
            
            if ( s.find("1")!= string::npos ) {
                cout << cal(s,'1') << endl ;
            } else {
                cout << cal(s,'2') * 2 << endl ;
            }
        }
    }
};

int main ( ) {
    Main main ;
    main.solve() ;
}

