#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Calculator {
private:
    int k; // Parameter k
    int answer = 0; // Variable to store the answer
    bool isCalculate = false; // Flag to check if calculation is done
    vector<list<int>> lists; // List of lists to store relationships

public:
    // Constructor to initialize the Calculator object
    Calculator(int n, int k, vector<int>& as) {
        this->k = k;
        lists.resize(n); // Resize the lists to store n elements
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                lists[as[i]].push_back(i); // Add relationship between elements
            } else if (as[i] > 0) {
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

    // DFS method to traverse through the lists
    void dfs(int a, int pre) {
        int h = 0; // Variable to store the height of the tree
        for (int i : lists[a]) {
            dfs(i, a); // Recursively calculate the height
            h = max(h, i); // Update the height
        }
        if (pre > 0 && h == k - 1) {
            h = 0; // Reset height if condition is met
            answer++; // Increment answer if condition is met
        } else {
            h++; // Increment height otherwise
        }
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        as[i]--; // Adjust the input value by subtracting 1
    }

    // Initialize the Calculator object and calculate the result
    Calculator calc(n, k, as);
    cout << calc.calculate() << endl;

    return 0;
}

