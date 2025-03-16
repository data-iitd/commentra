

#include <bits/stdc++.h>

using namespace std;

// Initialize FastReader for reading input
class FastReader {
public:
    BufferedReader br;
    StringTokenizer st;

    // Initialize the FastReader
    FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    // Read a string token
    string next() {
        while (st == null ||!st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    // Read an integer
    int nextInt() {
        return Integer.parseInt(next());
    }

    // Read a long integer
    long nextLong() {
        return Long.parseLong(next());
    }

    // Read a double
    double nextDouble() {
        return Double.parseDouble(next());
    }

    // Read a line
    string nextLine() {
        string str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
};

int main() {
    // Initialize FastReader for reading input
    FastReader sc;
    PrintWriter out;

    // Read the number of test cases
    int n = sc.nextInt();

    // Initialize an array 'a' to store the frequency of each number
    int a[33] = {0};

    // Read each test case and update the frequency of the number in the array 'a'
    for (int i = 0; i < n; i++) {
        int num = sc.nextInt(); // Read a number
        int index = rec(num);   // Get the index of the number in the array 'a'
        a[index]++;             // Increment the frequency of the number in the array 'a'
    }

    // Calculate the answer and print it
    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
        answer += summ;                                 // Add the sum to the answer
    }
    cout << (long) answer << endl; // Print the answer as a long integer

    return 0;
}

// A helper method to get the index of a number in the array 'a'
int rec(long x) {
    int answer = 0;

    // Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
    for (int k = 31; k >= 0; k--) {
        if ((x & (1 << k))!= 0) // If the k-th bit is set
            answer++;             // Increment the answer
    }

    return answer;
}

// End of code
