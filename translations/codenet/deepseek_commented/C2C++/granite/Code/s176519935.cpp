
#include<iostream>

// Define the heap array and its size
long long heap[100000], sz = 0;

// Function to insert a new element into the heap
void push(int x) {
    int i = sz++; // Increment the size of the heap and store the current index
    // Bubble up the new element to its correct position
    while (i > 0) {
        int p = (i - 1) / 2; // Calculate the parent index
        if (heap[p] >= x) break; // If the parent is greater or equal, break the loop
        heap[i] = heap[p]; // Move the parent down
        i = p; // Move to the parent index
    }
    heap[i] = x; // Insert the new element
}

// Function to remove and return the maximum element from the heap
int pop() {
    int ret = heap[0]; // Store the root (maximum) element
    int x = heap[--sz]; // Get the last element and decrement the size of the heap
    int i = 0; // Start from the root
    // Bubble down the new root to its correct position
    while (i * 2 + 1 < sz) {
        int a = i * 2 + 1, b = i * 2 + 2; // Calculate the children indices
        if (b < sz && heap[b] > heap[a]) a = b; // Choose the larger child
        if (heap[a] <= x) break; // If the children are less than or equal to the element, break the loop
        heap[i] = heap[a]; // Move the child up
        i = a; // Move to the child index
    }
    heap[i] = x; // Insert the element
    return ret; // Return the removed element
}

int main() {
    int n, m, i, j;
    long long a[100000];
    std::cin >> n >> m; // Read the number of elements and the number of operations
    for (i = 0; i < n; i++) std::cin >> a[i]; // Read the elements into the array
    for (i = 0; i < n; i++) push(a[i]); // Push each element into the heap
    for (i = 0; i < m; i++) {
        long long tm = pop(); // Pop the maximum element
        tm /= 2; // Halve the element
        push(tm); // Push the halved element back into the heap
    }
    long long ans = 0;
    for (i = 0; i < n; i++) ans += heap[i]; // Calculate the sum of the heap elements
    std::cout << ans << std::endl; // Print the result
    return 0;
}

