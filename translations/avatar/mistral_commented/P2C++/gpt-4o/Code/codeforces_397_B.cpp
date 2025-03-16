#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CodeforcesTask397BSolution {
private:
    string result;                     // Initialize an empty string to store the result
    int t;                             // Initialize the number of queries to 0
    vector<vector<int>> queries;      // Initialize a vector to store the queries

public:
    // Constructor method with initializations
    CodeforcesTask397BSolution() : t(0) {}

    // Method to read input
    void read_input() {
        cin >> t;                       // Read the number of queries from the input
        queries.resize(t);             // Resize the queries vector to hold t queries
        for (int i = 0; i < t; ++i) {
            vector<int> query(3);       // Create a vector to hold the current query
            for (int j = 0; j < 3; ++j) {
                cin >> query[j];         // Read each element of the query
            }
            queries[i] = query;          // Store the current query in the queries vector
        }
    }

    // Method to process the task
    void process_task() {
        vector<string> res;             // Initialize an empty vector to store the results of each query
        for (const auto& query : queries) { // Iterate through each query in the queries vector
            int k = query[0] / query[1]; // Calculate the value of k for the current query
            res.push_back((k * query[2] >= query[0]) ? "Yes" : "No"); // Append the result (Yes or No) for the current query to the results vector
        }
        result = "";                     // Initialize result as an empty string
        for (const auto& r : res) {
            result += r + "\n";          // Join the results vector with newline character and store it in the result string
        }
    }

    // Method to get the result
    string get_result() const {
        return result;                  // Return the result string
    }
};

// Main method to run the code
int main() {
    CodeforcesTask397BSolution solution; // Create an instance of the CodeforcesTask397BSolution class
    solution.read_input();                // Read the input
    solution.process_task();              // Process the task
    cout << solution.get_result();        // Print the result
    return 0;
}

// <END-OF-CODE>
