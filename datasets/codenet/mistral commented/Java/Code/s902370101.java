import java.util.Scanner; // Importing the Scanner class for user input

public class Main {
	public static void main(String[] args) { // Main method where the execution starts
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object for reading user input
		int n; // Declaring an integer variable 'n' to store the size of the array

		// Reading the size of the array from the user input
		System.out.print("Enter the size of the array: ");
		n = sc.nextInt();

		int[] array = new int[n]; // Creating an integer array of size 'n'

		int max = 0; // Declaring and initializing an integer variable 'max' to store the maximum element
		int min = 10000; // Declaring and initializing an integer variable 'min' to store the minimum element

		// Reading elements of the array from the user input and finding the maximum and minimum elements
		for (int i = 0; i < array.length; i++) {
			int num; // Declaring an integer variable 'num' to store the current element being read

			// Reading the current element from the user input
			System.out.print("Enter element " + (i + 1) + ": ");
			num = sc.nextInt();

			array[i] = num; // Assigning the read element to the corresponding index in the array

			// Updating the maximum and minimum elements if the current element is greater or smaller respectively
			if (max < num) {
				max = num;
			}

			if (min > num) {
				min = num;
			}
		}

		// Printing the difference between the maximum and minimum elements
		System.out.println("The difference between the maximum and minimum elements is: " + (max - min));

		sc.close(); // Closing the Scanner object to free up system resources
	}
}
