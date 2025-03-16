#include <stdio.h>
#include <stdlib.h>

// Main function starts here
int main() {

    // Creating FastReader object to read input
    FastReader sc = new FastReader();

    // Creating PrintWriter object to write output
    PrintWriter pw = new PrintWriter(stdout);

    // Reading the first integer input
    int x = sc.nextInt();

    // Initializing count variable to 0
    int count = 0;

    // Initializing temporary variable tmp with the value of x
    int tmp = x;

    // Setting x to 0
    x = 0;

    // Starting a while loop that runs until x is equal to 360
    while (x!= 360) {

        // Adding the value of tmp to x
        x = x + tmp;

        // If x is greater than 360, then subtract 360 from it
        if (x > 360) {
            x = x - 360;
        }

        // Incrementing the count variable
        count++;
    }

    // Printing the value of count to the console using PrintWriter
    pw.println(count);

    // Closing the PrintWriter and FastReader objects
    pw.close();
    sc.close();

    // Returning from main function
    return 0;
}

// FastReader class starts here
class FastReader {

    // Creating BufferedReader object to read input
    BufferedReader br;

    // Creating StringTokenizer object to tokenize input
    StringTokenizer st;

    // Constructor method initializes BufferedReader object
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    // Method to read a string token
    String next() {
        while (st == null ||!st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // Method to read an integer input
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Method to read a long integer input
    long nextLong() {
        return Long.parseLong(next());
    }

    // Method to read a double input
    double nextDouble() {
        return Double.parseDouble(next());
    }

    // Method to read a full line of input
    String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

