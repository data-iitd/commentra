
import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read the count of numbers to be processed
		int count = Integer.parseInt(sc.next());
		
		// Initialize an array to store the giving numbers
		int[] givingNumbers = new int[count];
		
		// Read the numbers and store them in the array
		for(int i = 0; i < count; i++){
			givingNumbers[i] = Integer.parseInt(sc.next());
		}
		
		// Reverse the order of numbers and print them
		for(int i = count - 1; 0 <= i; i--){
			System.out.print(givingNumbers[i]);
			if(i > 0){
				System.out.print(" ");
			}
		}
		
		// Print a newline character to move to the next line
		System.out.println();
		
		// Close the Scanner to free up resources
		sc.close();
	}

}

