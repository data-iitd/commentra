#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Main method to start the program
int main ( ) {
    // Initialize input and output streams
    istream & inputStream = cin;
    ostream & outputStream = cout;

    // Create InputReader and PrintWriter objects
    InputReader in(inputStream);
    PrintWriter out(outputStream);

    // Create Solution object and call its solve method
    Solution sol;
    sol.solve(in, out);

    // Close the output stream
    out.close();
}

// Private nested class for solving the problem
class Solution {
    // Method to solve the problem
    private:
        void solve ( InputReader & in , PrintWriter & out ) {
            // Read input: number of elements n and the number of summands k
            int n = in.ni();
            int k = in.ni();

            // Read input array a of size n
            vector<int> a(n);
            for ( int i = 0 ; i < n ; ++ i ) {
                a[i] = in.ni(); // Read next element of array a
            }

            // Sort the array a in parallel using std::sort()
            sort(a.begin(), a.end());

            // Calculate the answer: sum of first k elements of sorted array a
            int ans = 0;
            for ( int i = 0 ; i < k ; ++ i ) {
                ans += a[i];
            }

            // Write the answer to the output stream
            out.println(ans);
        }
};

// Nested static class for reading input
class InputReader {
    // Initialize reader and tokenizer
    private:
        istream & reader;
        stringstream tokenizer;

    // Constructor to initialize InputReader with input stream
    public:
        InputReader(istream & stream) : reader(stream) {
            tokenizer = stringstream();
        }

    // Method to read a string token
    private:
        string n() {
            while (tokenizer.str().empty() || !tokenizer.good()) {
                try {
                    getline(reader, tokenizer.str());
                } catch (exception e) {
                    throw runtime_error(e.what());
                }
            }
            return tokenizer.str();
        }

    // Method to read an integer
    private:
        int ni() {
            return stoi(n());
        }
};

// Nested static class for writing output
class PrintWriter {
    // Initialize writer
    private:
        ostream & writer;

    // Constructor to initialize PrintWriter with output stream
    public:
        PrintWriter(ostream & stream) : writer(stream) {
        }

    // Method to write a string to the output stream
    private:
        void println(string s) {
            writer << s << endl;
        }

    // Method to write an integer to the output stream
    private:
        void println(int i) {
            writer << i << endl;
        }

    // Method to close the output stream
    private:
        void close() {
            writer.close();
        }
};

// 