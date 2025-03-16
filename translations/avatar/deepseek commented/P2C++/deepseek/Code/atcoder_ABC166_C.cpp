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

    // Step 2: Create a list of positions (p) from 1 to n
    for (int i = 0; i < n; ++i) {
        p[i] = i + 1;
    }

    // Step 3: Input the heights (h) of the nodes
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    // Step 4: Create a dictionary (hp) mapping positions to heights
    std::unordered_map<int, int> hp;
    for (int i = 0; i < n; ++i) {
        hp[p[i]] = h[i];
    }

    // Step 5: Initialize a dictionary (path) to store the adjacency list of the graph
    for (int i = 1; i <= n; ++i) {
        path[i] = std::vector<int>();
    }

    // Step 6: Input the edges of the graph and populate the adjacency list
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    // Step 7: Count the number of nodes that are the highest in their neighborhoods
    int c = 0;
    for (auto& [i, v] : path) {
        bool f = false;
        for (int j : v) {
            if (hp[i] <= hp[j]) {
                f = true;
                break;
            }
        }
        if (!f) {
            ++c;
        }
    }

    // Step 8: Output the count of such nodes
    std::cout << c << std::endl;

    return 0;
}
