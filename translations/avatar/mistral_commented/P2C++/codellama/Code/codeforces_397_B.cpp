
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CodeforcesTask397BSolution {

    private:
        string result;                     // Initialize an empty string to store the result
        int t;                             // Initialize the number of queries to 0
        vector<vector<int>> queries;       // Initialize an empty list to store the queries

    public:
        // Constructor method with initializations
        CodeforcesTask397BSolution() {
            result = "";
            t = 0;
            queries = vector<vector<int>>();
        }

        // Method to read input
        void read_input() {
            cin >> t;                      // Read the number of queries from the input
            for (int i = 0; i < t; i++) {   // Iterate through each query
                vector<int> query;          // Initialize an empty list to store the current query
                for (int j = 0; j < 3; j++) {
                    int x;                  // Initialize a variable to store the current element of the current query
                    cin >> x;               // Read the current element of the current query from the input
                    query.push_back(x);     // Add the current element to the current query
                }
                queries.push_back(query);   // Add the current query to the queries list
            }
        }

        // Method to process the task
        void process_task() {
            vector<string> res;             // Initialize an empty list to store the results of each query
            for (int i = 0; i < t; i++) {   // Iterate through each query in the queries list
                int k = queries[i][0] / queries[i][1]; // Calculate the value of k for the current query
                res.push_back(k * queries[i][2] >= queries[i][0] ? "Yes" : "No"); // Append the result (Yes or No) for the current query to the results list
            }
            result = "\n";                  // Join the results list with newline character and store it in the result string
            for (int i = 0; i < t; i++) {
                result += res[i] + "\n";
            }
        }

        // Method to get the result
        string get_result() {
            return result;                 // Return the result string
        }
};

int main() {
    CodeforcesTask397BSolution Solution;   // Create an instance of the CodeforcesTask397BSolution class
    Solution.read_input();                 // Read the input
    Solution.process_task();               // Process the task
    cout << Solution.get_result();         // Print the result
    return 0;
}

