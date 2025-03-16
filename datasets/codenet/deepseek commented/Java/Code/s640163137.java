import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main (String[] args) throws IOException{
		// Step 1: Reading Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()); // Read the number of elements
		int[] a = new int[n]; // Create an array to hold the elements
		String[] elements = br.readLine().split(" "); // Read the elements as a space-separated string
		
		// Step 2: Populate the array
		for (int i = 0; i < n; i++){
			a[i] = Integer.parseInt(elements[i]); // Convert each element from string to integer and store in the array
		}
		
		// Step 3: Sorting using Selection Sort
		int swapCount = 0; 
		
		for(int i = 0; i < a.length; i++){
			int mini = i; // Assume the current index has the minimum value
			
			// Find the index of the minimum element in the unsorted part of the array
			for(int j = i; j < a.length; j++){
				if(a[j] < a[mini]){
					mini = j; // Update the index of the minimum element
				}
			}
			
			// Swap the found minimum element with the first element of the unsorted part
			if (mini != i){
				int v = a[mini];
				a[mini] = a[i];
				a[i] = v;
				
				swapCount++; // Increment the swap count
			}
		}
		
		// Step 4: Output the sorted array and the number of swaps
		String ans = String.valueOf(a[0]);
		for (int i = 1; i < a.length; i++){
			ans += " " + a[i];
		}
		
		System.out.println(ans); // Print the sorted array
		System.out.println(swapCount); // Print the number of swaps
	}
}
