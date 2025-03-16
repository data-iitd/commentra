#include <bits/stdc++.h>
using namespace std;

// FastReader class to handle fast input
class FastReader {
    public:
    // BufferedReader for input
    static BufferedReader br;
    // StringTokenizer for input
    static StringTokenizer st;
    // Method to read the next token from input
    static string next() {
        // Check if there are no more tokens available
        while (st == NULL ||!st.hasMoreElements()) {
            try {
                // Read a new line and tokenize it
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        // Return the next token
        return st.nextToken();
    }
    // Method to read the next integer from input
    static int nextInt() {
        return Integer.parseInt(next());
    }
    // Method to read the next long from input
    static long nextLong() {
        return Long.parseLong(next());
    }
    // Method to read the next double from input
    static double nextDouble() {
        return Double.parseDouble(next());
    }
    // Method to read the next line from input
    static String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
};

// Declare the FastReader class as static member of Main class
BufferedReader FastReader::br = new BufferedReader(new InputStreamReader(System.in));
StringTokenizer FastReader::st = new StringTokenizer("");

int main() {
    // Create an instance of FastReader for input
    FastReader sc = new FastReader();

    // Read two integers n and m from input
    int n = sc.nextInt();
    int m = sc.nextInt();

    // Reverse the integer m and store the result in t
    int t = reverse(m);

    // Print the sum of t and n
    cout << t + n << endl;

    return 0;
}

// Method to reverse the digits of an integer n
int reverse(int n) {
    // If n is a single digit, return n multiplied by 10
    if (n < 10) return n * 10;

    int t = n, r = 0;

    // Loop to reverse the digits of n
    while (t > 0) {
        r = (r * 10) + t % 10; // Add the last digit of t to r
        t = t / 10; // Remove the last digit from t
    }

    // Return the reversed integer
    return r;
}

