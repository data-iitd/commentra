
import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in); // Initialize Scanner object for reading input
	/**
	 * @param args the command line arguments
	 */
	static int[] score; // Declare an integer array named 'score' to store the scores
	static int number; // Declare an integer variable named 'number' to read the number of scores
	public static void main(String[] args) {
		while(read()){ // Read input data until there is no more data to read
			slove(); // Solve the problem for the given input data
		}
	}
	static boolean read(){ // Read the next input data
		number = sc.nextInt(); // Read the number of scores
		if(number == 0) // If the number of scores is zero, return false to exit the loop
			return false;

		score = new int[number]; // Allocate memory for the 'score' array with the size of 'number'
		for(int i = 0; i < number; i++){ // Read each score and store it in the 'score' array
			score[i] = sc.nextInt();
		}
		return true; // Return true to continue reading the next input data
	}
	static void slove(){ // Solve the problem for the given input data
		java.util.Arrays.sort(score); // Sort the 'score' array in ascending order
		int sum = 0; // Initialize a variable 'sum' to store the sum of middle scores
		for(int i = 1; i < number-1; i++){ // Iterate through the 'score' array from the second element to the second last element
			sum = sum + score[i]; // Add the current score to the sum
		}
		System.out.println(sum/(number-2)); // Print the average of middle scores
	}
}

