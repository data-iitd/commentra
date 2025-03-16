#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>

typedef int32_t i32;
typedef int64_t i64;

// Define a structure for a directed edge in the graph
struct DirectedEdge {
    int32_t vertex; // The destination vertex of the edge
    int32_t next;   // The index of the next edge in the adjacency list
};

// Define a structure for the directed graph
struct DirectedGraph {
    std::vector<DirectedEdge> edge; // Array of edges
    std::vector<int32_t> start;      // Array of start pointers for each vertex
    int32_t pointer;                 // Current number of edges
    int32_t vertex_num;              // Number of vertices

    DirectedGraph(int vertex_num) : start(vertex_num, -1), pointer(0), vertex_num(vertex_num) {
        edge.reserve(1); // Reserve space for edges
    }
};

// Define the modulo constant
const i32 mod = 1000000007;

// Function to compute r^n % mod using exponentiation by squaring
i32 mod_pow(i32 r, i32 n) {
    i32 t = 1;
    i32 s = r;
    while (n > 0) {
        if (n & 1) t = (i64)t * s % mod; // If n is odd, multiply t by s
        s = (i64)s * s % mod; // Square s
        n >>= 1; // Halve n
    }
    return t;
}

// Define a structure for a node in the dynamic programming array
struct DPNode {
    i32 one;  // Number of ways to have exactly one edge
    i32 zero; // Number of ways to have exactly zero edges
};

// Function to merge two nodes in the dynamic programming array
DPNode merge(DPNode *a, i32 n) {
    i64 one = 0;
    i64 zero = 1;
    i64 total = 1;
    for (i32 i = 0; i < n; ++i) {
        one = (one * a[i].zero + zero * a[i].one) % mod; // Calculate the number of ways to have exactly one edge
        zero = zero * a[i].zero % mod; // Calculate the number of ways to have exactly zero edges
        total = total * (a[i].zero + a[i].one) % mod; // Calculate the total number of ways
    }
    return {one, (total + mod - one) % mod}; // Return the merged node
}

// Define the type for values stored in the deque
typedef DPNode DequeVal;

// Define a structure for the deque
struct Deque {
    std::vector<DequeVal> array;
    size_t front;
    size_t last;
    size_t mask;

    Deque() : front(0), last(0), mask(1) {
        array.resize(2);
    }

    size_t get_size() const {
        return (last + (~front + 1)) & mask;
    }

    void realloc() {
        std::vector<DequeVal> new_array(2 * (mask + 1));
        size_t k = 0;
        for (size_t i = front; i != last; i = (i + 1) & mask) {
            new_array[k++] = array[i];
        }
        array = std::move(new_array);
        front = 0;
        last = k;
        mask = 2 * mask + 1;
    }

    DequeVal get_at(size_t x) const {
        return array[(front + x) & mask];
    }

    void assign_at(size_t x, DequeVal v) {
        array[(front + x) & mask] = v;
    }

    void push_front(DequeVal v) {
        if (((last + 1) & mask) == front) {
            realloc();
        }
        front = (front + mask) & mask;
        array[front] = v;
    }
};

// Function to compare the sizes of two deques
int cmp_deque_size(const Deque *a, const Deque *b) {
    i32 d = a->get_size() - b->get_size();
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

// Function to run the main logic of the program
void run() {
    i32 n;
    std::cin >> n; // Read the number of vertices
    std::vector<i32> p(n + 1); // Array to store parent pointers
    std::vector<i32> depth(n + 1); // Array to store depths of vertices
    std::vector<i32> cnt(n + 1, 0); // Array to count vertices at each depth
    cnt[0] = 1; // There is one way to have zero edges (the root itself)
    DirectedGraph g(n + 1); // Initialize the graph

    for (i32 i = 1; i <= n; ++i) {
        std::cin >> p[i]; // Read the parent of each vertex
        g.edge.push_back({i, g.start[p[i]]}); // Add the edge to the graph
        g.start[p[i]] = g.pointer++; // Update the start pointer
        depth[i] = depth[p[i]] + 1; // Calculate the depth of each vertex
        cnt[depth[i]]++; // Increment the count of vertices at the current depth
    }

    std::vector<Deque*> dp(n + 1, nullptr); // Array to store dynamic programming results
    std::vector<Deque*> child(n + 1, nullptr); // Array to store child deques
    std::vector<DPNode> lst(n + 1); // Array to store merged nodes

    for (i32 i = n; i >= 0; --i) {
        i32 v = i;
        if (g.start[v] == -1) {
            dp[v] = new Deque();
            dp[v]->push_front({1, 1}); // Initialize the dp array for leaf nodes
            continue;
        }
        i32 len = 0;
        for (i32 p = g.start[v]; p != -1; p = g.edge[p].next) {
            i32 u = g.edge[p].vertex;
            child[len++] = dp[u]; // Collect child deques
        }
        if (len > 1) {
            std::sort(child.begin(), child.begin() + len, cmp_deque_size); // Sort child deques by size
            for (i32 d = 0; d < (i32)child[1]->get_size(); ++d) {
                i32 j = 0;
                for (; j < len && d < (i32)child[j]->get_size(); ++j) {
                    lst[j] = child[j]->get_at(d); // Get nodes at the current depth
                }
                child[0]->assign_at(d, merge(lst.data(), j)); // Merge nodes and assign to the first child deque
            }
            for (i32 j = 1; j < len; ++j) {
                delete child[j]; // Free memory of unused child deques
            }
        }
        dp[v] = child[0]; // Assign the merged deque to the current vertex
        dp[v]->push_front({1, 1}); // Add the current node to the dp array
    }

    i64 ans = 0;
    for (i32 i = 0; i < (i32)dp[0]->get_size(); ++i) {
        ans += (i64)mod_pow(2, n + 1 - cnt[i]) * dp[0]->get_at(i).one % mod; // Calculate the answer
    }
    std::cout << ans % mod << std::endl; // Print the result
}

// Main function to run the program
int main() {
    run();
    return 0;
}

// <END-OF-CODE>
