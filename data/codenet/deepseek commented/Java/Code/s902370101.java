
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Initialize Scanner to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read the number of elements in the array
		int n = sc.nextInt();
		
		// Initialize an array of size n to store the elements
		int[] array = new int[n];
		
		// Initialize variables to track the maximum and minimum values
		int max = 0;
		int min = 10000;
		
		// Read n elements from the input and store them in the array
		for (int i = 0; i < array.length; i++) {
			array[i] = sc.nextInt();
			
			// Update max if the current element is greater than the current max
			if (max < array[i]) {
				max = array[i];
			}
			
			// Update min if the current element is less than the current min
			if (min > array[i]) {
				min = array[i];
			}
		}
		
		// Print the difference between the maximum and minimum values in the array
		System.out.println(max - min);
		
		// Close the Scanner to free up resources
		sc.close();
	}
}

