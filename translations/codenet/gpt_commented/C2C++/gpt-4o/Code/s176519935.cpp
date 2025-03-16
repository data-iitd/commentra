#include <iostream>
#include <vector>

using namespace std;

// Declare a max heap and a variable to track the size of the heap
vector<long long> heap;
long long sz = 0;

// Function to insert an element into the max heap
void push(long long x) {
    int i = sz++; // Increment size and set current index
    // Percolate up to maintain heap property
    while (i > 0) {
        int p = (i - 1) / 2; // Calculate parent index
        if (heap[p] >= x) break; // If parent is greater or equal, stop
        heap[i] = heap[p]; // Move parent down
        i = p; // Move index to parent
    }
    heap[i] = x; // Place the new element in its correct position
}

// Function to remove and return the maximum element from the max heap
long long pop() {
    long long ret = heap[0]; // Store the maximum element
    long long x = heap[--sz]; // Remove the last element and decrease size
    int i = 0; // Start from the root of the heap
    // Percolate down to maintain heap property
    while (i * 2 + 1 < sz) {
        int a = i * 2 + 1, b = i * 2 + 2; // Left and right child indices
        // Choose the larger child
        if (b < sz && heap[b] > heap[a]) a = b; 
        if (heap[a] <= x) break; // If the larger child is less than or equal to x, stop
        heap[i] = heap[a]; // Move the larger child up
        i = a; // Move index to the child
    }
    heap[i] = x; // Place the removed element in its correct position
    return ret; // Return the maximum element
}

int main() {
    int n, m;
    cin >> n >> m; // Read the number of elements and the number of operations
    heap.resize(n); // Resize the heap to hold n elements
    // Read the elements into the heap
    for (int i = 0; i < n; i++) cin >> heap[i];
    sz = n; // Set the size of the heap

    // Build the max heap
    for (int i = (sz / 2) - 1; i >= 0; i--) {
        // Percolate down to maintain heap property
        int idx = i;
        while (idx * 2 + 1 < sz) {
            int a = idx * 2 + 1, b = idx * 2 + 2; // Left and right child indices
            // Choose the larger child
            if (b < sz && heap[b] > heap[a]) a = b; 
            if (heap[a] <= heap[idx]) break; // If the larger child is less than or equal to the current node, stop
            swap(heap[idx], heap[a]); // Swap the larger child up
            idx = a; // Move index to the child
        }
    }

    // Perform m operations of removing the max element and pushing back half of it
    for (int i = 0; i < m; i++) {
        long long tm = pop(); // Get the maximum element
        tm /= 2; // Halve the maximum element
        push(tm); // Push the halved value back into the heap
    }

    long long ans = 0; // Variable to accumulate the sum of remaining elements
    // Calculate the sum of all elements remaining in the heap
    for (int i = 0; i < sz; i++) ans += heap[i];
    // Print the final result
    cout << ans << endl;
    return 0; // Return success
}

// <END-OF-CODE>
