#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Calculator {
private:
    int k; // Parameter k
    int answer = 0; // Variable to store the answer
    bool isCalculate = false; // Flag to check if calculation is done
    std::vector<std::vector<int>> lists; // List of lists to store relationships

public:
    // Constructor to initialize the Calculator object
    Calculator(int n, int k, const std::vector<int>& as) : k(k), lists(n) {
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (i > 0) {
                lists[j].push_back(i); // Add relationship between elements
            } else if (j > 0) {
                answer++; // Increment answer if condition is met
            }
        }
    }

    // Method to calculate the result using DFS
    int calculate() {
        if (!isCalculate) {
            dfs(0, 0); // Start DFS from the root node
            isCalculate = true; // Set the flag to true
        }
        return answer; // Return the calculated answer
    }

private:
    // DFS method to traverse through the lists
    int dfs(int a, int pre) {
        int h = 0; // Variable to store the height of the tree
        for (int i : lists[a]) {
            h = std::max(h, dfs(i, a)); // Recursively calculate the height
        }
        if (pre > 0 && h == k - 1) {
            h = 0; // Reset height if condition is met
            answer++; // Increment answer if condition is met
        } else {
            h++; // Increment height otherwise
        }
        return h; // Return the height
    }
};

void run() {
    int n; // Number of elements
    int k; // Some parameter k
    std::vector<int> as; // Vector to store input values

    // Read input values
    std::cin >> n >> k; // Read the number of elements and parameter k
    as.resize(n);
    for (int i = 0; i < n; i++) {
        int value;
        std::cin >> value;
        as[i] = value - 1; // Read each element and adjust by subtracting 1
    }

    // Initialize the Calculator object and calculate the result
    std::cout << Calculator(n, k, as).calculate() << std::endl;
}

int main() {
    // Start the thread to handle input and output
    std::thread t(run);
    t.join(); // Wait for the thread to finish
    return 0;
}

// <END-OF-CODE>
