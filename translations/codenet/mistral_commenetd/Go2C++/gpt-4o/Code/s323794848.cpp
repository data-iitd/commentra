// Include necessary headers
#include <iostream> // For I/O operations
#include <vector>  // For using vectors
#include <string>  // For string operations
#include <algorithm> // For reverse operation

// Define a deque (double ended queue) class
class Deque {
public:
    std::vector<char> front; // Vector to store the front elements
    std::vector<char> back;  // Vector to store the back elements

    // Function to check if deque is empty at the front
    bool isEmptyFront() {
        return front.empty();
    }

    // Function to check if deque is empty at the back
    bool isEmptyBack() {
        return back.empty();
    }

    // Function to add an element at the back of the deque
    void pushBack(char v) {
        back.push_back(v);
    }

    // Function to add an element at the front of the deque
    void pushFront(char v) {
        front.push_back(v);
    }

    // Function to remove an element from the back of the deque and return it
    bool popBack(char &v) {
        if (!isEmptyBack()) {
            v = back.back();
            back.pop_back();
            return true;
        } else if (!isEmptyFront()) {
            v = front.front();
            front.erase(front.begin());
            return true;
        }
        return false;
    }

    // Function to remove an element from the front of the deque and return it
    bool popFront(char &v) {
        if (!isEmptyFront()) {
            v = front.back();
            front.pop_back();
            return true;
        } else if (!isEmptyBack()) {
            v = back.front();
            back.erase(back.begin());
            return true;
        }
        return false;
    }

    // Function to get an element from the deque by its index
    char get(int idx) {
        int tot = front.size() + back.size();
        if (idx < tot) {
            if (idx < front.size()) {
                return front[front.size() - 1 - idx];
            } else {
                return back[idx - front.size()];
            }
        }
        return '\0'; // Return null character if index is invalid
    }
};

// Function to reverse a given string
std::string rev(const std::string &s) {
    std::string r = s;
    std::reverse(r.begin(), r.end());
    return r;
}

// Structure to hold operation details
struct Operation {
    bool rev = false; // Flag for reverse operation
    bool front = false; // Flag for front operation
    char c; // Character to be added
};

int main() {
    // Read the input string S from the standard input
    std::string S;
    std::cin >> S;

    // Read the number of operations Q from the standard input
    int Q;
    std::cin >> Q;

    // Initialize a vector of operations ops with the given size
    std::vector<Operation> ops(Q);

    // Read the operations one by one and store them in the ops vector
    for (int i = 0; i < Q; i++) {
        int q;
        std::cin >> q;
        if (q == 1) {
            ops[i].rev = true;
        } else {
            int f;
            std::cin >> f >> ops[i].c;
            ops[i].front = (f == 1);
        }
    }

    // Initialize an array of sums sum with the given size
    std::vector<int> sum(Q + 1, 0);

    // Iterate through the operations and calculate their sums
    for (int i = Q - 1; i >= 0; i--) {
        if (ops[i].rev) {
            sum[i] = sum[i + 1] + 1;
        } else {
            sum[i] = sum[i + 1];
        }
    }

    // If the sum of the first operation is odd, reverse the input string
    if (sum[0] % 2 == 1) {
        S = rev(S);
    }

    // Initialize an empty deque deq
    Deque deq;

    // Iterate through the operations and process them based on their type
    for (int i = 0; i < Q; i++) {
        if (!ops[i].rev) {
            if (ops[i].front) {
                if (sum[i] % 2 == 1) {
                    deq.pushFront(ops[i].c);
                } else {
                    deq.pushBack(ops[i].c);
                }
            } else {
                if (sum[i] % 2 == 1) {
                    deq.pushBack(ops[i].c);
                } else {
                    deq.pushFront(ops[i].c);
                }
            }
        }
    }

    // Write the result to the standard output
    for (int i = deq.front.size() - 1; i >= 0; i--) {
        std::cout << deq.front[i];
    }
    std::cout << S; // Write the input string to the standard output
    for (int i = 0; i < deq.back.size(); i++) {
        std::cout << deq.back[i];
    }
    std::cout << std::endl;

    return 0;
}

// <END-OF-CODE>
