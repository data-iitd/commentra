#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Calculator {
private:
    int k; // Variable to store the value of k
    int answer = 0; // Variable to store the answer
    bool isCalculate = false; // Flag to check if calculation has been done
    vector<list<int>> lists; // Vector of lists to store the adjacency list representation of the graph

public:
    Calculator(int n, int k, vector<int>& as) {
        this->k = k;
        lists.resize(n);

        // Building the adjacency list representation of the graph
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (0 < i) {
                lists[j].push_back(i); // Adding the index of the current node to the list of neighbors of node j
            } else if (0 < j) {
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
            h = max(h, dfs(i, a)); // Updating the height by calling the dfs recursively on the neighbor and taking the maximum height
        }

        if (0 < pre && h == k - 1) { // Checking if the current node is at the desired height k - 1 from the previous node
            h = 0; // Resetting the height to 0 if it is
            answer++; // Incrementing the answer if the current node is at the desired height
        } else {
            h++; // Incrementing the height if the current node is not the base case
        }

        return h; // Returning the height of the current node
    }
};

int main() {
    int n, k; // Variables to store the number of test cases and value of k
    vector<int> as; // Vector to store the input array

    cin >> n >> k; // Reading input values for n and k

    // Reading input values for the array as
    as.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        as[i]--; // Decrementing the value by 1 to convert to 0-based index
    }

    // Creating an instance of the Calculator class and calculating the result
    Calculator calc(n, k, as);
    cout << calc.calculate() << endl; // Printing the result of the calculation

    return 0;
}

