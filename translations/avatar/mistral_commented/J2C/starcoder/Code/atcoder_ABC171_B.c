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

int main(int argc, char **argv) {
    // Initialize input and output streams
    FILE * inputStream = stdin;
    FILE * outputStream = stdout;

    // Create InputReader and PrintWriter objects
    InputReader in = new InputReader(inputStream);
    PrintWriter out = new PrintWriter(outputStream);

    // Create Solution object and call its solve method
    Solution sol = new Solution();
    sol.solve(in, out);

    // Close the output stream
    out.close();
}

// Private nested class for solving the problem
class Solution {
    // Method to solve the problem
    void solve ( InputReader in, PrintWriter out ) {
        // Read input: number of elements n and the number of summands k
        int n = in.ni();
        int k = in.ni();

        // Read input array a of size n
        int* a = new int[n];
        for ( int i = 0 ; i < n ; ++ i ) {
            a[i] = in.ni(); // Read next element of array a
        }

        // Sort the array a in parallel using Arrays.parallelSort()
        Arrays.parallelSort(a);

        // Calculate the answer: sum of first k elements of sorted array a
        int ans = 0;
        for ( int i = 0 ; i < k ; ++ i ) {
            ans += a[i];
        }

        // Write the answer to the output stream
        out.println(ans);
    }
}

// Nested static class for reading input
class InputReader {
    // Initialize reader and tokenizer
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    // Constructor to initialize InputReader with input stream
    InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    // Method to read a string token
    String n() {
        while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    // Method to read an integer
    int ni() {
        return Integer.parseInt(n());
    }
}

