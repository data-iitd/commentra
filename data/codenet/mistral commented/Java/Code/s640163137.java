
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main (String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // create a BufferedReader object to read input from the console

		// read the first line which contains the number of elements in the array
		int n = Integer.parseInt(br.readLine());

		// create an integer array of size n
		int[] a = new int[n];

		// read the second line which contains the elements of the array separated by spaces
		String[] elements = br.readLine().split(" ");

		// initialize the array with the read elements
		for (int i = 0; i < n; i++){
			a[i] = Integer.parseInt(elements[i]); // parse each string element to an integer and assign it to the corresponding index in the array
		}

		int swapCount = 0; // initialize a counter to keep track of the number of swaps made during the sorting process

		// sort the array using bubble sort algorithm
		for(int i = 0; i < a.length; i++){
			int mini = i; // initialize a variable to keep track of the index of the minimum element in the unsorted part of the array

			// find the index of the minimum element in the unsorted part of the array
			for(int j = i; j < a.length; j++){
				if(a[j] < a[mini]){
					mini = j; // update the index of the minimum element if a[j] is smaller than a[mini]
				}
			}

			// swap the elements if the minimum element is not at its initial position
			if (mini != i){
				int v = a[mini]; // store the value of the minimum element
				a[mini] = a[i]; // swap the values of the elements at indices i and mini
				a[i] = v; // swap the values back to their original positions for the next iteration

				swapCount++; // increment the swapCount variable after each swap
			}
		}

		// print the sorted array and the number of swaps made during the sorting process
		String ans = String.valueOf(a[0]); // convert the first element of the array to a string and initialize the answer string
		for (int i = 1; i < a.length; i++){
			ans += " " + a[i]; // concatenate the string representation of each element with a space in between to form the final answer string
		}

		System.out.println(ans); // print the sorted array
		System.out.println(swapCount); // print the number of swaps made during the sorting process
	}
}