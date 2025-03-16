#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdint.h>

int main() {
    // Set up input and output streams
    FILE * inputStream = stdin; 
    FILE * outputStream = stdout; 
    
    // Create an InputReader to read input from the input stream
    InputReader in = new InputReader(inputStream); 
    
    // Create a PrintWriter to write output to the output stream
    PrintWriter out = new PrintWriter(outputStream); 
    
    // Create an instance of the Solution class to solve the problem
    Solution sol = new Solution(); 
    
    // Call the solve method to process the input and produce output
    sol.solve(in, out); 
    
    // Close the PrintWriter to flush the output
    out.close(); 
}

private static class Solution { 
    private void solve(InputReader in, PrintWriter out) { 
        // Read the number of elements (n) and the number of smallest elements to sum (k)
        int n = in.ni(), k = in.ni(); 
        
        // Initialize an array to hold the input numbers
        int[] a = new int[n]; 
        
        // Read n integers from input and store them in the array
        for (int i = 0; i < n; ++i) 
            a[i] = in.ni(); 
        
        // Sort the array in parallel to arrange numbers in ascending order
        Arrays.parallelSort(a); 
        
        // Initialize a variable to hold the sum of the smallest k elements
        int ans = 0; 
        
        // Sum the first k elements of the sorted array
        for (int i = 0; i < k; ++i) 
            ans += a[i]; 
        
        // Output the result (sum of the smallest k elements)
        out.println(ans); 
    } 
}

private static class InputReader { 
    private BufferedReader reader; 
    private StringTokenizer tokenizer; 
    
    // Constructor to initialize the InputReader with an InputStream
    private InputReader(InputStream stream) { 
        reader = new BufferedReader(new InputStreamReader(stream), 32768); 
        tokenizer = null; 
    } 
    
    // Method to read the next token as a String
    private String n() { 
        // Read a new line if the tokenizer is null or has no more tokens
        while (tokenizer == null ||!tokenizer.hasMoreTokens()) { 
            try { 
                tokenizer = new StringTokenizer(reader.readLine()); 
            } catch (IOException e) { 
                throw new RuntimeException(e); 
            } 
        } 
        return tokenizer.nextToken(); 
    } 
    
    // Method to read the next token as an integer
    private int ni() { 
        return Integer.parseInt(n()); 
    } 
}

