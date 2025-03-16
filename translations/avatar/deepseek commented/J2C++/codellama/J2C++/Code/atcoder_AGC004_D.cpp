
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MyRunnable : public Runnable {
public:
    void run() {
        int n; // Number of elements
        int k; // Some parameter k
        vector<int> as; // List to store input values

        // Read input values using cin
        cin >> n >> k; // Read the number of elements and parameter k
        for (int i = 0; i < n; i++) {
            int a; // Temporary variable to store input value
            cin >> a; // Read each element
            as.push_back(a - 1); // Adjust by subtracting 1
        }

        // Initialize the Calculator object and calculate the result
        cout << Calculator(n, k, as).calculate() << endl;
    }
};

class Calculator {
private:
    int k; // Parameter k
    int answer = 0; // Variable to store the answer
    bool isCalculate = false; // Flag to check if calculation is done
    vector<vector<int>> lists; // List of lists to store relationships

    // Constructor to initialize the Calculator object
    Calculator(int n, int k, vector<int> as) {
        this->k = k;
        for (int i = 0; i < n; i++) {
            this->lists.push_back(vector<int>()); // Initialize each list in the lists
        }
        for (int i = 0; i < n; i++) {
            int j = as[i];
            if (0 < i) {
                this->lists[j].push_back(i); // Add relationship between elements
            } else if (0 < j) {
                this->answer++; // Increment answer if condition is met
            }
        }
    }

    // Method to calculate the result using DFS
    int calculate() {
        if (!this->isCalculate) {
            this->dfs(0, 0); // Start DFS from the root node
            this->isCalculate = true; // Set the flag to true
        }
        return this->answer; // Return the calculated answer
    }

    // DFS method to traverse through the lists
    int dfs(int a, int pre) {
        int h = 0; // Variable to store the height of the tree
        for (int i : this->lists[a]) {
            h = max(h, this->dfs(i, a)); // Recursively calculate the height
        }
        if (0 < pre && h == this->k - 1) {
            h = 0; // Reset height if condition is met
            this->answer++; // Increment answer if condition is met
        } else {
            h++; // Increment height otherwise
        }
        return h; // Return the height
    }
};

int main() {
    // Start the MyRunnable thread to handle input and output
    thread(MyRunnable()).detach();
    return 0;
}

