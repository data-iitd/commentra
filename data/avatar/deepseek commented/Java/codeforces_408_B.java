
import java.io.* ; 
import java.lang.* ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner s = new Scanner ( System.in ) ; // Initialize Scanner to read input
        String s1 = s.next ( ) ; // Read first string
        String s2 = s.next ( ) ) ; // Read second string
        
        // Check if the strings are valid using the isValid method
        if ( isValid ( s1 , s2 ) == false ) { 
            System.out.println ( - 1 ) ; // Print -1 if strings are not valid
        } else { 
            HashMap < Character , Integer > m1 = new HashMap < > ( ) ; // Create HashMap for s1
            HashMap < Character , Integer > m2 = new HashMap < > ( ) ; // Create HashMap for s2
            
            // Populate the HashMap with the frequency of each character in s1
            for ( char c : s1.toCharArray ( ) ) { 
                if ( m1.containsKey ( c ) ) { 
                    m1.put ( c , m1.get ( c ) + 1 ) ; 
                } else { 
                    m1.put ( c , 1 ) ; 
                } 
            }
            
            // Populate the HashMap with the frequency of each character in s2
            for ( char c : s2.toCharArray ( ) ) { 
                if ( m2.containsKey ( c ) ) { 
                    m2.put ( c , m2.get ( c ) + 1 ) ; 
                } else { 
                    m2.put ( c , 1 ) ; 
                } 
            }
            
            int ans = 0 ; // Initialize answer variable
            HashSet < Character > hs = new HashSet < > ( ) ; // Create HashSet to track processed characters
            
            // Iterate over the characters of s2
            for ( char c : s2.toCharArray ( ) ) { 
                if ( ! hs.contains ( c ) ) { 
                    hs.add ( c ) ; // Mark character as processed
                    int x1 = m1.get ( c ) ; // Get frequency of character in s1
                    int x2 = m2.get ( c ) ; // Get frequency of character in s2
                    x1 = Math.min ( x1 , x2 ) ; // Calculate minimum frequency
                    ans += x1 ; // Add minimum frequency to answer
                } 
            }
            
            System.out.println ( ans ) ; // Print the final answer
        } 
    }
    
    // Method to check if s1 is a valid substring of s2
    public static boolean isValid ( String s1 , String s2 ) { 
        int n1 = s1.length ( ) ; 
        int n2 = s2.length ( ) ; 
        HashMap < Character , Boolean > map = new HashMap < > ( ) ; 
        
        // Populate the map with characters from s1
        for ( char c : s1.toCharArray ( ) ) { 
            map.put ( c , true ) ; 
        }
        
        // Check if all characters of s1 are present in s2
        for ( char c : s2.toCharArray ( ) ) { 
            if ( ! map.containsKey ( c ) ) return false ; 
        }
        
        return true ; 
    } 
}

