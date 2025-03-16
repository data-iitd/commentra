
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws java.lang.Exception{
		Scanner sc = new Scanner(System.in);
		// Create a Scanner object'sc' for reading input from the standard input

		int n = sc.nextInt();
		// Read the number of elements n from the standard input

		int m = sc.nextInt();
		// Read the number of queries m from the standard input

		long long[] a = new long[n];
		// Declare a long long array 'a' of size n for storing the input elements

		for(int i = 0; i < n; i++) a[i] = sc.nextLong();
		// Read the elements of the array 'a' from the standard input

		PriorityQueue<Long> pq = new PriorityQueue<Long>();
		// Create a PriorityQueue object 'pq' for storing the elements in the heap

		for(int i = 0; i < n; i++) pq.add(a[i]);
		// Add each element of the array 'a' to the heap using the 'add' function

		for(int i = 0; i < m; i++){
			long tm = pq.poll();
			// Pop an element from the heap

			tm /= 2;
			// Divide the popped element by 2

			pq.add(tm);
			// Add the divided element back to the heap using the 'add' function
		}
		// Perform m queries by popping an element from the heap, dividing it by 2, and adding it back to the heap

		long long ans = 0;
		// Initialize the variable ans to 0 for storing the sum of the elements in the heap

		for(int i = 0; i < n; i++) ans += pq.poll();
		// Calculate the sum of the elements in the heap using a loop

		System.out.println(ans);
		// Print the sum of the elements in the heap to the standard output
	}
}

