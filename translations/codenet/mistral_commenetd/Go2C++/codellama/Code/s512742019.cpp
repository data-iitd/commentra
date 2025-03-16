
#include <bits/stdc++.h>

using namespace std;

// I/O
class Scanner {
    std::cin >> std::noskipws;
    std::istream_iterator<char> it(std::cin);
    std::istream_iterator<char> end;
    std::string token;
    public:
        Scanner() {}
        bool hasNext() {
            return it != end;
        }
        template <typename T>
        T next() {
            while (!hasNext()) {
                token.clear();
                std::cin >> token;
                it = std::istream_iterator<char>(std::cin);
            }
            std::istringstream stream(token);
            T result;
            stream >> result;
            return result;
        }
        template <typename T>
        vector<T> nextVector(int n) {
            vector<T> result(n);
            for (int i = 0; i < n; i++) {
                result[i] = next<T>();
            }
            return result;
        }
};

// Helper functions for reading different data types from the scanner
template <typename T>
T next() {
    Scanner scanner;
    return scanner.next<T>();
}

template <typename T>
vector<T> nextVector(int n) {
    Scanner scanner;
    return scanner.nextVector<T>(n);
}

// Arithmetic
template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T abs(T a) {
    return a > 0 ? a : -a;
}

template <typename T>
T pow(T a, T b) {
    T result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

template <typename T>
T ceil(T a, T b) {
    return a % b == 0 ? a / b : a / b + 1;
}

// Sort
template <typename T>
struct RuneSlice {
    vector<T> arr;
    int len() {
        return arr.size();
    }
    bool less(int i, int j) {
        return arr[i] < arr[j];
    }
    void swap(int i, int j) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

// Main
const int MOD = int(1e+9) + 7; // Modulus value for modular arithmetic
const int INF = 1 << 60;       // Infinite value for comparison

// Mon represents a monster with x-coordinate and height
struct Mon {
    int x, h;
};

// Mons is a slice of Mon structures
struct Mons {
    vector<Mon> arr;
    int len() {
        return arr.size();
    }
    bool less(int i, int j) {
        return arr[i].x < arr[j].x;
    }
    void swap(int i, int j) {
        Mon temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

// Node represents a node in the priority queue with x-coordinate and damage
struct Node {
    int x, h;
};

// Queue is a priority queue implemented as a slice with custom push, pop, and isEmpty functions
struct Queue {
    vector<Node> arr;
    void push(Node v) {
        arr.push_back(v);
    }
    Node first() {
        return arr[0];
    }
    Node pop() {
        Node result = arr[0];
        arr.erase(arr.begin());
        return result;
    }
    bool isEmpty() {
        return arr.size() == 0;
    }
};

// Main function initializes variables, sorts monsters, and calculates the answer
int main() {
    // Initialize a new Scanner and a bufio.Writer for input/output
    Scanner scanner;
    // Read input values N, D, and A from the scanner
    int N, D, A = scanner.next<int>(), scanner.next<int>(), scanner.next<int>();

    // Initialize a slice of Mon structures called M
    Mons M;

    // Read x and h values for each Mon and store them in the M slice
    for (int i = 0; i < N; i++) {
        M.arr.push_back(Mon{scanner.next<int>(), scanner.next<int>()});
    }

    // Sort the M slice based on x-coordinates
    sort(M.arr.begin(), M.arr.end(), [](Mon a, Mon b) {
        return a.x < b.x;
    });

    // Initialize an empty priority queue called q
    Queue q;

    // Initialize answer variable ans to 0 and total variable total to 0
    int ans = 0, total = 0;

    // Iterate through each Mon in the sorted M slice
    for (int i = 0; i < N; i++) {
        // Current Mon
        Mon m = M.arr[i];

        // While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
        while (!q.isEmpty() && q.first().x < m.x) {
            // Pop the first Node from the priority queue
            total -= q.pop().h;
        }

        // If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
        if (total < m.h) {
            int damage = m.h - total;
            ans += damage;
            q.push(Node{m.x + 2*D, damage});
            total += damage;
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

