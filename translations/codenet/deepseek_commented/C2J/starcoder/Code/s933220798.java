import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a; // Declare a variable to store the input value
		double ave = 0; // Initialize a variable to store the sum of values
		int i; // Declare a counter variable for the loop
		
		// Loop to read 5 values from the user
		for (i = 0; i < 5; i++){
			a = sc.nextDouble(); // Read a double value from the user and store it in 'a'
			if (a <= 40){ // Check if the value of 'a' is less than or equal to 40
				ave += 40; // Add 40 to 'ave' if the condition is true
			}
			else {
				ave += a; // Add the value of 'a' to 'ave' if the condition is false
			}
		}
		//System.out.println(ave); // Uncommented line to print the sum of values
		
		ave /= 5.0; // Calculate the average of the values added to 'ave' and divide by 5.0
		
		System.out.println(ave); // Print the average value rounded to the nearest integer
		
		sc.close(); // Close the scanner
	}

}
