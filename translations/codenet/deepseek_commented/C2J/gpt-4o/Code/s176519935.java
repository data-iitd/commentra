import java.util.Scanner;

public class MaxHeap {
    // Define the heap array and its size
    private static long[] heap = new long[100000];
    private static int sz = 0;

    // Function to insert a new element into the heap
    public static void push(long x) {
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
    public static long pop() {
        long ret = heap[0]; // Store the root (maximum) element
        long x = heap[--sz]; // Get the last element and decrement the size of the heap
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        long[] a = new long[100000];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong(); // Read the elements into the array
        }
        for (int i = 0; i < n; i++) {
            push(a[i]); // Push each element into the heap
        }
        for (int i = 0; i < m; i++) {
            long tm = pop(); // Pop the maximum element
            tm /= 2; // Halve the element
            push(tm); // Push the halved element back into the heap
        }
        long ans = 0;
        for (int i = 0; i < sz; i++) {
            ans += heap[i]; // Calculate the sum of the heap elements
        }
        System.out.println(ans); // Print the result
        scanner.close();
    }
}

// <END-OF-CODE>
