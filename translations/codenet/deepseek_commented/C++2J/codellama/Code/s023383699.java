import java.util.Scanner; // Import the Scanner class

public class Main { // The Main class is the entry point of the program
	public static void main(String[] args) { // The main function is the entry point of the program
		Scanner sc = new Scanner(System.in); // Create a new Scanner object
		int x = sc.nextInt(); // Take an integer input from the user and store it in x
		System.out.println(x*x*x); // Output the cube of the input value x
	}
}
