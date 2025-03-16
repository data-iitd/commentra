
import java.util.Scanner;
// Import the Scanner class for reading input from the standard input

class Heap{
	// Declare a class 'Heap' for performing the heap operations

	private long[] heap;
	// Declare a long array 'heap' for storing the elements of the heap

	private int sz;
	// Declare an integer variable 'sz' for storing the size of the heap

	public Heap(int n){
		// Declare a constructor for initializing the heap

		heap = new long[n];
		// Initialize the array 'heap' with the size 'n'

		sz = 0;
		// Initialize the variable 'sz' to 0
	}

	public void push(long x){
		// Declare a function 'push' for adding an element to the heap

		int i = sz++;
		// i is the index of the newly added element in the heap

		while(i > 0){
			// Perform the heapify operation from the bottom to the top

			int p = (i - 1) / 2;
			// p is the index of the parent node of the current node i

			if(heap[p] >= x) break;
			// If the parent node is greater than or equal to the current node, then break the loop

			heap[i] = heap[p];
			// Swap the parent node with the current node

			i = p;
			// Move to the parent node
		}

		heap[i] = x;
		// Assign the value x to the current node
	}

	public long pop(){
		// Declare a function 'pop' for popping an element from the heap

		long ret = heap[0];
		// ret stores the value of the root node

		long x = heap[--sz];
		// x is the last element in the heap after popping the root node

		int i = 0;
		// i is the index of the current node

		while(i * 2 + 1 < sz){
			// Perform the heapify operation from the bottom to the top after popping the root node

			int a = i * 2 + 1;
			// a is the index of the left child node of the current node i

			int b = i * 2 + 2;
			// b is the index of the right child node of the current node i

			if(b < sz && heap[b] > heap[a]) a = b;
			// If the right child node has a greater value than the left child node, then assign the index of the right child node to a

			if(heap[a] <= x) break;
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
}

public class Main{
	// Declare a class 'Main' for the main function

	public static void main(String[] args){
		// Declare a function 'main' for the main function

		Scanner sc = new Scanner(System.in);
		// Declare a Scanner object 'sc' for reading input from the standard input

		int n = sc.nextInt();
		// Read the number of elements n from the standard input

		int m = sc.nextInt();
		// Read the number of queries m from the standard input

		long[] a = new long[n];
		// Declare a long array 'a' of size n for storing the input elements

		for(int i = 0; i < n; i++) a[i] = sc.nextLong();
		// Read the elements of the array 'a' from the standard input

		Heap h = new Heap(n);
		// Declare a Heap object 'h' for performing the heap operations

		for(int i = 0; i < n; i++) h.push(a[i]);
		// Add each element of the array 'a' to the heap using the 'push' function

		for(int i = 0; i < m; i++){
			long tm = h.pop();
			// Pop an element from the heap

			tm /= 2;
			// Divide the popped element by 2

			h.push(tm);
			// Add the divided element back to the heap using the 'push' function
		}
		// Perform m queries by popping an element from the heap, dividing it by 2, and adding it back to the heap

		long ans = 0;
		// Initialize the variable ans to 0 for storing the sum of the elements in the heap

		for(int i = 0; i < n; i++) ans += h.heap[i];
		// Calculate the sum of the elements in the heap using a loop

		System.out.println(ans);
		// Print the sum of the elements in the heap to the standard output

		sc.close();
		// Close the Scanner object 'sc'
	}
}

