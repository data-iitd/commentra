
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in)); // Create a BufferedReader object to read input from the console

		String[] strs = reader.readLine().split(" "); // Read a line of input from the console and split it into an array of strings

		int[] nums = new int[strs.length]; // Create an integer array of size equal to the number of strings read from the input
		int top = 0; // Initialize a variable to keep track of the top index of the stack

		for (int i = 0; i < strs.length; i++) { // Iterate through each string in the array
			switch (strs[i].charAt(0)) { // Determine the operator based on the first character of the string
			case '+':
				top--; // Decrement the top index of the stack
				nums[top-1] += nums[top]; // Add the top two numbers in the stack and update the second number
				break;
			case '-':
				top--; // Decrement the top index of the stack
				nums[top-1] -= nums[top]; // Subtract the top number from the second number in the stack and update the second number
				break;
			case '*':
				top--; // Decrement the top index of the stack
				nums[top-1] *= nums[top]; // Multiply the top two numbers in the stack and update the second number
				break;
			default:
				nums[top] = Integer.parseInt(strs[i]); // If the string is a number, parse it and push it onto the stack
				top++; // Increment the top index of the stack
				break;
			}
			// Uncomment the following line to print the current state of the stack at each iteration
			// System.out.println(Arrays.toString(nums));
		}
		System.out.println(nums[0]); // Print the final result, which is the first number in the stack

	}
}

