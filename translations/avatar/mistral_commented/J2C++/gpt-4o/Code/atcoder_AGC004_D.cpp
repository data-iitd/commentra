#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class Calculator {
private:
    int k; // Variable to store the value of k
    int answer = 0; // Variable to store the answer
    bool isCalculate = false; // Flag to check if calculation has been done
    std::vector<std::vector<int>> lists; // 2D vector to store the adjacency list representation of the graph

public:
    Calculator(int n, int k, const std::vector<int>& as) : k(k), lists(n) {
        // Building the adjacency list representation of the graph
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (i > 0) {
                lists[j].push_back(i); // Adding the index of the current node to the list of neighbors of node j
            } else if (j > 0) {
                answer++; // Incrementing the answer if the input array contains a negative index
            }
        }
    }

    int calculate() {
        if (!isCalculate) {
            dfs(0, -1); // Performing Depth First Search (DFS) traversal starting from node 0 with previous node as -1
            isCalculate = true;
        }
        return answer;
    }

private:
    int dfs(int a, int pre) {
        int h = 0; // Variable to store the height of the current node in the DFS tree

        for (int i : lists[a]) { // Iterating through the neighbors of the current node
            h = std::max(h, dfs(i, a)); // Updating the height by calling the dfs recursively on the neighbor and taking the maximum height
        }

        if (pre > 0 && h == k - 1) { // Checking if the current node is at the desired height k - 1 from the previous node
            h = 0; // Resetting the height to 0 if it is
            answer++; // Incrementing the answer if the current node is at the desired height
        } else {
            h++; // Incrementing the height if the current node is not the base case
        }

        return h; // Returning the height of the current node
    }
};

void run() {
    int n; // Variable to store the number of test cases
    int k; // Variable to store the value of k
    std::vector<int> as; // Vector to store the input array

    std::cin >> n >> k; // Reading input values for n and k

    // Reading input values for the array as
    as.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> as[i];
        as[i]--; // Adjusting the index to be zero-based
    }

    // Printing the result of the calculation
    std::cout << Calculator(n, k, as).calculate() << std::endl;
}

int main() {
    std::thread t(run); // Creating a new thread to run the function
    t.join(); // Waiting for the thread to finish
    return 0;
}

// <END-OF-CODE>
