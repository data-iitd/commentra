import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		// Create a BufferedReader to read input from the standard input
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));

		// Read the input line and split it into an array of strings
		String[] strs = reader.readLine().split(" ");
		
		// Initialize an array to hold integers with the same length as the input array
		int[] nums = new int[strs.length];
		
		// Initialize a variable to keep track of the current position in the nums array
		int top = 0;
		
		// Process each element of the input array
		for (int i = 0; i < strs.length; i++) {
			// Check the first character of the string and perform the corresponding operation
			switch (strs[i].charAt(0)) {
			case '+':
				// Decrement top to point to the last added element
				top--;
				// Update the element before the last by adding it to the last element
				nums[top-1] = nums[top - 1] + nums[top];
				break;
			case '-':
				// Decrement top to point to the last added element
				top--;
				// Update the element before the last by subtracting the last element from it
				nums[top-1] = nums[top - 1] - nums[top];
				break;
			case '*':
				// Decrement top to point to the last added element
				top--;
				// Update the element before the last by multiplying it with the last element
				nums[top-1] = nums[top - 1] * nums[top];
				break;
			default:
				// Parse the string to an integer and add it to the nums array
				nums[top] = Integer.parseInt(strs[i]);
				// Increment top to point to the next position in the nums array
				top++;
				break;
			}
			// Uncomment the following line to print the array after each operation for debugging purposes
			// System.out.println(Arrays.toString(nums));
		}
		
		// Print the result, which is the first element of the nums array
		System.out.println(nums[0]);

	}
}
