import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class

	public static void main(String[] args){ // Starting point of the program

		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input
		int count = Integer.parseInt(sc.next()); // Reading the number of integers to be entered by the user

		// Allocating memory for an array of integers with the given size
		int[] givingNumbers = new int[count];

		// Reading numbers from the user and storing them in the array
		for(int i = 0; i< count;i++){
			givingNumbers[i] = Integer.parseInt(sc.next()); // Reading an integer from the user and storing it in the array
		}

		// Printing the numbers in reverse order
		for(int i = count-1; 0 <= i;i--){ // Starting the loop from the last index of the array and decrementing the index until it becomes 0
			System.out.print(givingNumbers[i]); // Printing the current number
			if(i > 0){ // Checking if the current index is not the first index
				System.out.print(" "); // Printing a space if it's not the first number
			}
		}

		System.out.println(); // Printing a new line after printing the reversed numbers
		sc.close(); // Closing the Scanner object to free up system resources
	}

}
