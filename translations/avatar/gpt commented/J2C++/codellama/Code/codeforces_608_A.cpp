#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cmath> 
#include <algorithm> 
using namespace std; 

class FastReader { 
    public: 
        FastReader() { 
            // Create a BufferedReader object for efficient input reading
            br = new BufferedReader(new InputStreamReader(System.in)); 
            // Create a StringTokenizer object for efficient string tokenization
            st = new StringTokenizer(""); 
        } 
        
        // Method to read the next token
        string next() { 
            // Read new line if no more tokens are available
            while (!st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } catch (IOException e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        
        // Method to read the next line
        string nextLine() { 
            string str = ""; 
            try { 
                str = br.readLine(); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
        
        // Methods to read different data types
        byte nextByte() { return Byte.parseByte(next()); } 
        short nextShort() { return Short.parseShort(next()); } 
        int nextInt() { return Integer.parseInt(next()); } 
        long nextLong() { return java.lang.Long.parseLong(next()); } 
        double nextDouble() { return Double.parseDouble(next()); } 
    private: 
        BufferedReader *br; 
        StringTokenizer *st; 
}; 

int main() { 
    // Initialize FastReader for efficient input reading
    FastReader in = new FastReader(); 
    // Create a Scanner object for standard input
    Scanner sc = new Scanner(System.in); 
    // Create a PrintWriter object for output
    PrintWriter o = new PrintWriter(System.out); 
    
    // Read the number of pairs (n) and the minimum score (s)
    int n = sc.nextInt(); 
    int s = sc.nextInt(); 
    
    // Initialize a variable to keep track of the maximum sum of pairs
    int max = 0; 
    
    // Loop through each pair of integers
    while (n-- > 0) { 
        // Read the two integers f and t
        int f = sc.nextInt(); 
        int t = sc.nextInt(); 
        // Update max if the sum of f and t is greater than the current max
        if (max < f + t) { 
            max = f + t; 
        } 
    } 
    
    // Print the maximum value between max and s
    o.println(Math.max(max, s)); 
    // Close the PrintWriter
    o.close(); 
} 

