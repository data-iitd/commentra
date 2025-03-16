
#include <iostream> 
#include <string> 
#include <map> 
#include <set> 

using namespace std ; 

// Function to check if s1 is a valid substring of s2
bool isValid ( string s1 , string s2 ) { 
    int n1 = s1.length ( ) ; 
    int n2 = s2.length ( ) ; 
    map < char , bool > map ; 
    
    // Populate the map with characters from s1
    for ( char c : s1 ) { 
        map [ c ] = true ; 
    }
    
    // Check if all characters of s1 are present in s2
    for ( char c : s2 ) { 
        if ( ! map [ c ] ) return false ; 
    }
    
    return true ; 
}

int main ( ) { 
    string s1 , s2 ; 
    cin >> s1 >> s2 ; 
    
    // Check if the strings are valid using the isValid method
    if ( isValid ( s1 , s2 ) == false ) { 
        cout << - 1 << endl ; 
    } else { 
        map < char , int > m1 , m2 ; 
        
        // Populate the HashMap with the frequency of each character in s1
        for ( char c : s1 ) { 
            if ( m1 [ c ] ) { 
                m1 [ c ] ++ ; 
            } else { 
                m1 [ c ] = 1 ; 
            } 
        }
        
        // Populate the HashMap with the frequency of each character in s2
        for ( char c : s2 ) { 
            if ( m2 [ c ] ) { 
                m2 [ c ] ++ ; 
            } else { 
                m2 [ c ] = 1 ; 
            } 
        }
        
        int ans = 0 ; 
        set < char > hs ; 
        
        // Iterate over the characters of s2
        for ( char c : s2 ) { 
            if ( hs.find ( c ) == hs.end ( ) ) { 
                hs.insert ( c ) ; 
                int x1 = m1 [ c ] ; 
                int x2 = m2 [ c ] ; 
                x1 = min ( x1 , x2 ) ; 
                ans += x1 ; 
            } 
        }
        
        cout << ans << endl ; 
    } 
    
    return 0 ; 
}

