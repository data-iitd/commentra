
#include <bits/stdc++.h>

using namespace std;

// A custom InputReader class for reading input efficiently
class FastReader {
public:
    FastReader() {
        // Initialize the FastReader
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    // Read a string token
    string next() {
        while (tokenizer == NULL ||!tokenizer->hasMoreElements()) {
            // If the tokenizer is not initialized or does not have any more elements, read the next line from the input
            string line;
            getline(cin, line);
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer->nextToken();
    }

    // Read an integer
    int nextInt() {
        return stoi(next());
    }

    // Read a long integer
    long long nextLong() {
        return stoll(next());
    }

    // Read a double
    double nextDouble() {
        return stod(next());
    }

    // Read a line
    string nextLine() {
        string str = "";
        getline(cin, str);
        return str;
    }

private:
    // A pointer to the StringTokenizer object
    StringTokenizer *tokenizer = NULL;
};

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

// Initialize FastReader for reading input
int main() {
    FastReader sc;
    cout << fixed << setprecision(10);

    // Read the number of test cases
    int n = sc.nextInt();

    // Initialize an array 'a' to store the frequency of each number
    int a[33];

    // Read each test case and update the frequency of the number in the array 'a'
    for (int i = 0; i < n; i++) {
        long num = sc.nextLong(); // Read a number
        int index = rec(num);     // Get the index of the number in the array 'a'
        a[index]++;               // Increment the frequency of the number in the array 'a'
    }

    // Calculate the answer and print it
    double answer = 0;
    for (int i = 0; i < 33; i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
        answer += summ;                                 // Add the sum to the answer
    }
    cout << answer << endl; // Print the answer

    return 0;
}

