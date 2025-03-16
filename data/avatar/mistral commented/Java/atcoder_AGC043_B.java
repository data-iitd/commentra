
import java.io.* ;  // Importing required Java packages for input/output operations
import java.util.* ;  // Importing required Java packages for string manipulation and tokenization

public class Main {
    
    // Declaring a private method to calculate the XOR operation on a given string with a specific character
    private int cal ( String s , char c ) {
        int n = s.length() ;  // Getting the length of the given string
        int m = n - 1 ;        // Initializing a variable 'm' to keep track of the index of the previous character
        int ans = 0 ;          // Initializing a variable 'ans' to store the result of XOR operation
        
        for ( int i = 0 ; i < n ; i ++ ) {  // Looping through each character in the given string
            if ( s.charAt(i) == c && (m & i) == i ) { // Checking if the current character is the given character and the difference between its index and the index of the previous character is a power of 2
                ans ^= 1 ;            // If yes, performing XOR operation on 'ans'
            }
        }
        
        return ans ;             // Returning the result of XOR operation
    }
    
    // Declaring a private method to read input and process it
    private void solve ( ) {
        int n = sc.nextInt() ;  // Reading the number of test cases
        
        for ( int testCase = 1 ; testCase <= n ; testCase++ ) {  // Looping through each test case
            int num = sc.nextInt() ; // Reading the length of the given string
            String s = sc.next() ;    // Reading the given string
            
            StringBuilder sb = new StringBuilder() ; // Creating a StringBuilder object to store the differences between adjacent characters
            
            for ( int i = 1 ; i < num ; i ++ ) { // Looping through each character except the first one in the given string
                sb.append(Math.abs(s.charAt(i) - s.charAt(i - 1))) ; // Appending the absolute difference between adjacent characters to the StringBuilder object
            }
            
            if ( num == 2 ) { // Checking if the given string has only two characters
                out.println(sb.charAt(0)) ; // If yes, printing the first character of the string
                continue ;                 // And moving to the next test case
            }
            
            s = sb.toString() ; // Converting the StringBuilder object to a String object
            
            if ( s.contains("1") ) { // Checking if the given string contains the character '1'
                out.println(cal(s,'1')) ; // If yes, printing the result of XOR operation on the given string with character '1'
            } else {
                out.println(cal(s,'2') * 2) ; // If no, performing XOR operation on the given string with character '2' and multiplying the result by 2
            }
        }
    }
    
    // Declaring static variables for input/output operations
    private static PrintWriter out ;
    private static MyScanner sc ;
    
    // Declaring a static class to read input
    private static class MyScanner {
        BufferedReader br ;
        StringTokenizer st ;
        
        private MyScanner ( ) {
            br = new BufferedReader(new InputStreamReader(System.in)) ;
        }
        
        String next ( ) {
            while ( st == null || ! st.hasMoreElements() ) {
                try {
                    st = new StringTokenizer(br.readLine()) ;
                } catch (IOException e) {
                    e.printStackTrace() ;
                }
            }
            return st.nextToken() ;
        }
        
        int nextInt ( ) {
            return Integer.parseInt(next()) ;
        }
        
        long nextLong ( ) {
            return Long.parseLong(next()) ;
        }
        
        double nextDouble ( ) {
            return Double.parseDouble(next()) ;
        }
    }
    
    // Declaring the main method to start the program
    public static void main ( String [ ] args ) {
        out = new PrintWriter(new BufferedOutputStream(System.out)) ;
        sc = new MyScanner() ;
        new Main().solve() ;
        out.close() ;
    }
}

I hope these comments will help you understand the logic of the code better. Let me know if you have any questions!