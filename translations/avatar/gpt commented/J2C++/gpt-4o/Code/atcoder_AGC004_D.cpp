#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Calculator {
private:
    int k; // Store the threshold value
    int answer = 0; // Store the final answer
    bool isCalculate = false; // Flag to check if calculation is done
    std::vector<std::vector<int>> lists; // Adjacency list representation

public:
    // Constructor to initialize the Calculator with input values
    Calculator(int n, int k, const std::vector<int>& as) : k(k), lists(n) {
        // Build the adjacency list based on the input values
        for (int i = 0; i < n; i++) {
            int j = as[i]; // Get the corresponding value
            if (i > 0) {
                lists[j].push_back(i); // Add edge to the adjacency list
            } else if (j > 0) {
                answer++; // Increment answer if the condition is met
            }
        }
    }

    // Method to calculate the answer
    int calculate() {
        // If calculation hasn't been performed yet, start the DFS
        if (!isCalculate) {
            dfs(0, 0); // Start DFS from node 0
            isCalculate = true; // Mark calculation as done
        }
        return answer; // Return the final answer
    }

    // Depth-First Search (DFS) method to explore the graph
    int dfs(int a, int pre) {
        int h = 0; // Height of the current node
        // Explore all adjacent nodes
        for (int i : lists[a]) {
            h = std::max(h, dfs(i, a)); // Recursively find the height
        }
        // Check if the conditions for incrementing the answer are met
        if (pre > 0 && h == k - 1) {
            h = 0; // Reset height if condition is met
            answer++; // Increment answer
        } else {
            h++; // Increment height
        }
        return h; // Return the height
    }
};

void run() {
    int n; // Number of elements
    int k; // A specific threshold value
    std::vector<int> as; // Vector to store input values

    // Use standard input to read values
    std::cin >> n >> k; // Read the number of elements and the threshold value
    as.resize(n);
    // Read n integers and adjust them (subtract 1) before adding to the vector
    for (int i = 0; i < n; i++) {
        std::cin >> as[i];
        as[i]--; // Adjust the value
    }

    // Create a Calculator instance and calculate the result, then print it
    std::cout << Calculator(n, k, as).calculate() << std::endl;
}

int main() {
    // Start a new thread to run the run function
    std::thread t(run);
    t.join(); // Wait for the thread to finish
    return 0;
}

// <END-OF-CODE>
