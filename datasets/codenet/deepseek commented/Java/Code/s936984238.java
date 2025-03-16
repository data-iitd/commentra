import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	/**
	 * @param args
	 */
	static int[] score; // Declares an array to store the scores
	static int number; // Declares an integer to store the number of scores
	
	public static void main(String[] args) {
		// Main loop to read input and solve the problem
		while(read()){
			slove();
		}
	}
	
	static boolean read(){
		number = sc.nextInt(); // Reads the number of scores
		if(number == 0)
			return false; // Returns false if the number is 0, indicating end of input
		
		score = new int[number]; // Initializes the score array with the number of scores
		for(int i = 0; i < number; i++){
			score[i] = sc.nextInt(); // Reads each score and stores it in the array
		}
		return true; // Returns true if input was read successfully
	}
	
	static void slove(){
		java.util.Arrays.sort(score); // Sorts the score array
		int sum = 0; // Initializes a variable to store the sum of the scores excluding the smallest and largest
		for(int i = 1; i < number-1; i++){
			sum = sum + score[i]; // Adds the middle scores to the sum
		}
		System.out.println(sum/(number-2)); // Prints the average of the middle scores
	}
}
