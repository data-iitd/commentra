import java.util.Scanner; // Importing the Scanner class for input

public class Main {

	public static void main(String[] args) {

		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in); // Creating a Scanner object to read input

		int X = scan.nextInt(); // Reading the first integer input
		int t = scan.nextInt(); // Reading the second integer input
		
		if(X>=t){ // Checking if X is greater than or equal to t
			System.out.println(X-t); // Printing the difference if X is greater than or equal to t
		} else if (X<t){ // Checking if X is less than t
			System.out.print(0); // Printing 0 if X is less than t
		}
		

	}
}
