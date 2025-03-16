#include <iostream>
#include <vector>
#include <thread>

class MyRunnable : public std::thread {
public:
    MyRunnable() : std::thread(nullptr, &MyRunnable::run, this) {}

    void run() {
        int n; // Number of elements
        int k; // A specific threshold value
        std::vector<int> as; // List to store input values

        // Use a Scanner to read input values from the console
        std::cin >> n >> k; // Read the number of elements and the threshold value
        // Read n integers and adjust them (subtract 1) before adding to the list
        for (int i = 0; i < n; i++) {
            int a;
            std::cin >> a;
            as.push_back(a - 1);
        }

        // Create a Calculator instance and calculate the result, then print it
        std::cout << Calculator(n, k, as).calculate() << std::endl;
    }
};

class Calculator {
public:
    Calculator(int n, int k, std::vector<int> as) : k(k), answer(0), isCalculate(false), lists(n) {
        // Initialize the adjacency list
        for (int i = 0; i < n; i++) {
            this->lists[i] = std::vector<int>();
        }
        // Build the adjacency list based on the input values
        for (int i = 0; i < n; i++) {
            int j = as[i]; // Get the corresponding value
            if (0 < i) {
                this->lists[j].push_back(i); // Add edge to the adjacency list
            } else if (0 < j) {
                this->answer++; // Increment answer if the condition is met
            }
        }
    }

    // Method to calculate the answer
    int calculate() {
        // If calculation hasn't been performed yet, start the DFS
        if (!this->isCalculate) {
            this->dfs(0, 0); // Start DFS from node 0
            this->isCalculate = true; // Mark calculation as done
        }
        return this->answer; // Return the final answer
    }

private:
    int k; // Store the threshold value
    int answer; // Store the final answer
    bool isCalculate; // Flag to check if calculation is done
    std::vector<std::vector<int>> lists; // Adjacency list representation

    // Depth-First Search (DFS) method to explore the graph
    int dfs(int a, int pre) {
        int h = 0; // Height of the current node
        // Explore all adjacent nodes
        for (int i : this->lists[a]) {
            h = std::max(h, this->dfs(i, a)); // Recursively find the height
        }
        // Check if the conditions for incrementing the answer are met
        if (0 < pre && h == this->k - 1) {
            h = 0; // Reset height if condition is met
            this->answer++; // Increment answer
        } else {
            h++; // Increment height
        }
        return h; // Return the height
    }
};

int main() {
    MyRunnable myRunnable; // Start a new thread to run the MyRunnable class
    myRunnable.join(); // Wait for the thread to finish
    return 0;
}

