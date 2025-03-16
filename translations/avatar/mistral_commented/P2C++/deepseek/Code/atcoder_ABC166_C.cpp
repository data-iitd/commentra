#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n);
    std::vector<int> h(n);
    std::unordered_map<int, std::vector<int>> path;

    // Read the second line of input containing the heights of the nodes
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
        p[i] = i + 1;
    }

    // Create a dictionary 'hp' using list comprehension to store node number as key and height as value
    std::unordered_map<int, int> hp;
    for (int i = 0; i < n; ++i) {
        hp[p[i]] = h[i];
    }

    // Initialize an empty dictionary 'path' to store the graph
    for (int i = 1; i <= n; ++i) {
        path[i] = std::vector<int>();
    }

    // Read 'm' lines of input containing edges and add them to the 'path' dictionary
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    // Initialize a counter 'c' to store the number of valid paths
    int c = 0;

    // Iterate through each node in the graph and check if it forms a valid path
    for (auto& [i, v] : path) {
        // Initialize a flag 'f' to check if the current node is a valid starting point
        bool f = false;
        // Iterate through each neighbor of the current node and check if it is a valid ending point
        for (int j : v) {
            // If the height of the current node is less than or equal to the height of its neighbor,
            // then it is not a valid path and we set the flag 'f' to true and break the loop
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        // If the flag 'f' is still false after checking all neighbors, then this node forms a valid path
        // and we increment the counter 'c'
        if (!f) {
            ++c;
        }
    }

    // Print the final result, i.e., the number of valid paths
    std::cout << c << std::endl;

    return 0;
}
