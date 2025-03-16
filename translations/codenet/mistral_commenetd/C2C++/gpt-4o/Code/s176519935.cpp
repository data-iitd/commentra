#include <iostream>
// Include the iostream library for input/output

using namespace std;

long long heap[100000], sz = 0;
// Declare a long long array 'heap' of size 100000 and initialize its size to zero

void push(int x) {
    int i = sz++;
    // i is the index of the newly added element in the heap

    while (i > 0) {
        // Perform the heapify operation from the bottom to the top
        int p = (i - 1) / 2;
        // p is the index of the parent node of the current node i

        if (heap[p] >= x) break;
        // If the parent node is greater than or equal to the current node, then break the loop

        heap[i] = heap[p];
        // Swap the parent node with the current node

        i = p;
        // Move to the parent node
    }

    heap[i] = x;
    // Assign the value x to the current node
}

int pop() {
    int ret = heap[0];
    // ret stores the value of the root node

    int x = heap[--sz];
    // x is the last element in the heap after popping the root node

    int i = 0;
    // i is the index of the current node

    while (i * 2 + 1 < sz) {
        // Perform the heapify operation from the bottom to the top after popping the root node

        int a = i * 2 + 1;
        // a is the index of the left child node of the current node i

        int b = i * 2 + 2;
        // b is the index of the right child node of the current node i

        if (b < sz && heap[b] > heap[a]) a = b;
        // If the right child node has a greater value than the left child node, then assign the index of the right child node to a

        if (heap[a] <= x) break;
        // If the value of the node to be swapped is less than or equal to the value of the current node, then break the loop

        heap[i] = heap[a];
        // Swap the values of the current node and the node to be swapped

        i = a;
        // Move to the node to be swapped
    }

    heap[i] = x;
    // Assign the value of the current node to the node that was swapped

    return ret;
    // Return the value of the root node before popping it
}

int main() {
    int n, m;
    // Declare variables n and m for reading input and performing calculations

    long long a[100000];
    // Declare a long long array 'a' of size n for storing the input elements

    cin >> n >> m;
    // Read the number of elements n and the number of queries m from the standard input

    for (int i = 0; i < n; i++) cin >> a[i];
    // Read the elements of the array 'a' from the standard input

    for (int i = 0; i < n; i++) push(a[i]);
    // Add each element of the array 'a' to the heap using the 'push' function

    for (int i = 0; i < m; i++) {
        long long tm = pop();
        // Pop an element from the heap

        tm /= 2;
        // Divide the popped element by 2

        push(tm);
        // Add the divided element back to the heap using the 'push' function
    }
    // Perform m queries by popping an element from the heap, dividing it by 2, and adding it back to the heap

    long long ans = 0;
    // Initialize the variable ans to 0 for storing the sum of the elements in the heap

    for (int i = 0; i < n; i++) ans += heap[i];
    // Calculate the sum of the elements in the heap using a loop

    cout << ans << endl;
    // Print the sum of the elements in the heap to the standard output

    return 0;
    // Return 0 to indicate the successful execution of the program
}
// <END-OF-CODE>
