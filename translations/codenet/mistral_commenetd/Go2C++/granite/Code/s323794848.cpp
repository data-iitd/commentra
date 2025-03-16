
// C++ code to solve the problem
#include <iostream>
#include <string>
#include <vector>

// Define a struct to represent an operation
struct op {
    bool rev; // Flag to indicate if the operation is to reverse the string
    bool front; // Flag to indicate if the operation is to add a character at the front
    char c; // Character to be added
};

// Define a deque (double ended queue) class
class Deque {
public:
    Deque() {} // Default constructor
    void pushBack(char c) { back.push_back(c); } // Push a character to the back of the deque
    void pushFront(char c) { front.push_front(c); } // Push a character to the front of the deque
    bool popBack(char *c) { // Pop a character from the back of the deque and return true if successful
        if (!back.empty()) {
            *c = back.back();
            back.pop_back();
            return true;
        } else if (!front.empty()) { // If the deque is empty at the back but not at the front
            *c = front.front(); // Pop the first element
            front.pop_front(); // Update the front vector
            return true;
        } else { // If the deque is empty at both front and back
            return false; // Return false
        }
    }
    bool popFront(char *c) { // Pop a character from the front of the deque and return true if successful
        if (!front.empty()) {
            *c = front.back();
            front.pop_back();
            return true;
        } else if (!back.empty()) { // If the deque is empty at the front but not at the back
            *c = back.front(); // Pop the last element
            back.pop_front(); // Update the back vector
            return true;
        } else { // If the deque is empty at both front and back
            return false; // Return false
        }
    }
    char get(int idx) { // Get a character from the deque by its index
        int tot = front.size() + back.size(); // Calculate the total length of the deque
        if (idx < tot) {
            if (idx < front.size()) {
                return front[front.size() - 1 - idx]; // Return the character at the specified index in the front vector
            } else {
                return back[idx - front.size()]; // Return the character at the specified index in the back vector
            }
        } else {
            return '\0'; // Return null character if the index is invalid
        }
    }
private:
    std::vector<char> front; // Front vector to store the characters
    std::vector<char> back; // Back vector to store the characters
};

// Function to reverse a given string
std::string rev(std::string s) {
    std::string r = ""; // Initialize an empty string to store the reversed string
    for (int i = s.length() - 1; i >= 0; i--) {
        r += s[i]; // Append the character at index i to the reversed string
    }
    return r; // Return the reversed string
}

int main() {
    std::string S; // Read the input string S from the standard input
    std::cin >> S;
    int Q; // Read the number of operations Q from the standard input
    std::cin >> Q;
    std::vector<op> ops(Q); // Initialize an array of operations ops with the given size
    for (int i = 0; i < Q; i++) {
        int q; // Read the type of operation (reverse or not)
        std::cin >> q;
        if (q == 1) { // If the operation is to reverse the string
            ops[i].rev = true; // Set the rev field to true
        } else {
            int f; // Read the front flag and the character c from the standard input
            std::cin >> f >> ops[i].c;
            if (f == 1) { // If the front flag is 1
                ops[i].front = true; // Set the front field to true
            }
        }
    }
    std::vector<int> sum(Q + 1, 0); // Initialize an array of sums sum with the given size
    for (int i = Q - 1; i >= 0; i--) { // Iterate through the remaining operations and calculate their sums
        if (ops[i].rev) {
            sum[i - 1] = sum[i] + 1; // If the current operation is to reverse the string, increment the previous sum
        } else {
            sum[i - 1] = sum[i]; // Else, set the previous sum to the current sum
        }
    }
    if (sum[0] % 2 == 1) { // If the sum of the first operation is odd, reverse the input string
        S = rev(S);
    }
    Deque deq; // Initialize an empty deque deq
    for (int i = 0; i < Q; i++) { // Iterate through the operations and process them based on their type
        if (!ops[i].rev) { // If the current operation is not to reverse the string
            if (ops[i].front) { // If the operation is to add a character at the front
                if (sum[i] % 2 == 1) { // If the previous sum is odd, push the character to the front of the deque
                    deq.pushFront(ops[i].c);
                } else {
                    deq.pushBack(ops[i].c); // Else, push the character to the end of the deque
                }
            } else { // Else, process the operation to add a character at the end
                if (sum[i] % 2 == 1) { // If the previous sum is odd, push the character to the end of the deque
                    deq.pushBack(ops[i].c);
                } else {
                    deq.pushFront(ops[i].c); // Else, push the character to the front of the deque
                }
            }
        }
    }
    std::string result = ""; // Initialize an empty string to store the result
    for (int i = len(deq.front) - 1; i >= 0; i--) { // Write the characters in the deque to the standard output
        result += deq.front[i];
    }
    result += S; // Write the input string to the standard output
    for (int i = 0; i < len(deq.back); i++) { // Write the characters in the deque to the standard output
        result += deq.back[i];
    }
    std::cout << result << std::endl; // Print the result
    return 0; // Return 0 to indicate successful execution
}

