
#include <bits/stdc++.h>

using namespace std;

class Main {
public:
    static void main(String[] args) {
        // Creating a new thread and passing it a new instance of MyRunnable class
        thread(MyRunnable()).start();
    }
};

class MyRunnable : public thread {
public:
    void run() {
        int n; // Variable to store the number of test cases
        int k; // Variable to store the value of k
        vector<int> as; // List to store the input array

        cin >> n >> k;

        // Reading input values for the array as
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            as.push_back(a - 1);
        }

        // Printing the result of the calculation
        cout << Calculator(n, k, as).calculate() << endl;
    }
};

class Calculator {
private:
    int k; // Variable to store the value of k
    int answer = 0; // Variable to store the answer
    bool isCalculate = false; // Flag to check if calculation has been done
    vector<vector<int>> lists; // 2D list to store the adjacency list representation of the graph

public:
    Calculator(int n, int k, vector<int> as) {
        this->k = k;
        lists = vector<vector<int>>(n);

        // Initializing the 2D list with vectors of size n
        for (int i = 0; i < n; i++) {
            lists[i] = vector<int>();
        }

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

// 