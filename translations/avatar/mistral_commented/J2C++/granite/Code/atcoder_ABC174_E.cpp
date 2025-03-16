
#include <bits/stdc++.h>
using namespace std;

// Define the main function to start the program
int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization between C++ and Java
    cin.tie(NULL); // Disable buffering for input/output

    // Define the input and output streams
    istream& inputStream = cin; // Initialize input stream from standard input
    ostream& outputStream = cout; // Initialize output stream to standard output

    // Define the InputReader class for reading input
    class InputReader {
    private:
        istream& stream; // Initialize the input stream
        string tokenizer; // Initialize the tokenizer string
        string nextToken() {
            while (tokenizer.empty()) {
                getline(stream, tokenizer); // Read a line from the input
                if (stream.eof()) throw runtime_error(); // If the end of the input is reached, throw a runtime exception
                tokenizer = string(tokenizer, 0, tokenizer.find_first_not_of(' ')); // Remove leading whitespace from the line
            }
            string ret = tokenizer; // Store the current token in the return value
            tokenizer = tokenizer.substr(tokenizer.find_first_of(' ') + 1); // Remove the current token from the tokenizer string
            return ret; // Return the current token
        }
    public:
        InputReader(istream& stream) : stream(stream) {} // Constructor to initialize the InputReader object with the given input stream
        int nextInt() {
            return stoi(nextToken()); // Parse the next token as an integer
        }
        vector<int> readArray(int n) {
            vector<int> a(n); // Initialize a vector of size n
            for (int i = 0; i < n; ++i) // Iterate through all the elements of the vector
                a[i] = nextInt(); // Read an integer as the next element
            return a; // Return the vector
        }
    };

    // Define the Solution class for the solution logic
    class Solution {
    public:
        void solve(InputReader& in, ostream& out) {
            int n = in.nextInt(); // Read the number of logs
            int k = in.nextInt(); // Read the number of days

            // Initialize the minimum and maximum possible days
            int min = 1, max = (int) 1e9 + 1000;

            // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
            while (min < max) {
                int mid = (min + max) / 2; // Calculate the middle day
                if (nei(mid, logsLength, k)) // If the number of days needed to cut the logs is greater than or equal to k
                    max = mid; // Narrow down the search space to the left
                else
                    min = mid + 1; // Narrow down the search space to the right
            }

            // Print the minimum day as the output
            out << min << endl; // Print the minimum day as the output
        }
    private:
        bool nei(int mid, vector<int>& logsLength, int k) {
            int daysNeeded = 0; // Initialize the days needed to zero

            // Iterate through all the logs and calculate the days needed to cut them
            for (int log : logsLength) {
                daysNeeded += (log + mid - 1) / mid; // Calculate the days needed to cut the current log
                k -= daysNeeded; // Subtract the days needed from the remaining days
                if (k < 0) // If the remaining days are not sufficient to cut all the logs
                    return false; // Return false to indicate that the middle day is not the answer
            }

            // If all the logs have been cut, return true to indicate that the middle day is the answer
            return true;
        }
    };

    // Create an InputReader object and a Solution object
    InputReader in(inputStream); // Create an InputReader object
    Solution sol; // Create a Solution object
    sol.solve(in, outputStream); // Call the solve method of Solution object

    return 0; // Return 0 to indicate successful execution
}

