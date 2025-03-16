#include <iostream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <climits> 
#include <cassert> 
using namespace std; 

#define INF 1000000000 
#define EPS 1e-9 
#define LN 1000000000 
#define N 1000000000 
#define M 1000000000 
#define MOD 1000000007 
#define MAX 1000000000 
#define MIN -1000000000 
#define PI acos(-1.0) 
#define DEBUG 1 

class Main { 
    public: 
        static void main(string[] args) { 
            // Set up input and output streams
            InputStream inputStream = System.in; 
            OutputStream outputStream = System.out; 
            
            // Create an InputReader to read input from the input stream
            InputReader in = new InputReader(inputStream); 
            
            // Create a PrintWriter to write output to the output stream
            PrintWriter out = new PrintWriter(outputStream); 
            
            // Create an instance of TaskD to solve the problem
            TaskD solver = new TaskD(); 
            
            // Call the solve method with test number, input reader, and output writer
            solver.solve(1, in, out); 
            
            // Close the PrintWriter to flush the output
            out.close(); 
        } 

        static class TaskD { 
            public void solve(int testNumber, InputReader in, PrintWriter out) { 
                // Read the input string S
                string S = in.next(); 
                int score = 0; // Initialize score to zero
                
                // Iterate through each character in the string S
                for (int i = 0; i < S.length(); i++) { 
                    // Determine the character for 'my' based on the index (even or odd)
                    char my = i % 2 == 0 ? 'g' : 'p'; 
                    
                    // Get the character from the input string at the current index
                    char his = S.charAt(i); 
                    
                    // Compare 'my' and 'his' characters to update the score
                    if (my != his) { 
                        // Increment score if 'my' is 'p', otherwise decrement
                        score += my == 'p' ? 1 : -1; 
                    } 
                } 
                
                // Output the final score
                out.println(score); 
            } 
        } 

        static class InputReader { 
            public BufferedReader reader; 
            public StringTokenizer tokenizer; 
            
            // Constructor to initialize BufferedReader and StringTokenizer
            public InputReader(InputStream stream) { 
                reader = new BufferedReader(new InputStreamReader(stream), 32768); 
                tokenizer = null; 
            } 
            
            // Method to read the next token from the input
            public string next() { 
                // Keep reading until we have a token available
                while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
                    try { 
                        // Read a line and create a new StringTokenizer
                        tokenizer = new StringTokenizer(reader.readLine()); 
                    } catch (IOException e) { 
                        throw new RuntimeException(e); 
                    } 
                } 
                // Return the next token
                return tokenizer.nextToken(); 
            } 
        } 
    } 

    // 