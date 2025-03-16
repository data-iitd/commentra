import java.util.Scanner; // Step 1: Include the standard input/output library.
public class Main {
	public static void main(String[] args) { // Step 2: Define the main function.
		Scanner sc = new Scanner(System.in); // Step 3: Create a Scanner object.
		int a,b,h; // Step 4: Declare three integer variables a, b, and h.
		
		// Step 5: Read three integer values from the user and store them in a, b, and h.
		a = sc.nextInt();
		b = sc.nextInt();
		h = sc.nextInt();
		
		// Step 6: Calculate the area of a trapezoid using the formula (a+b)*h/2.
		System.out.println((a+b)*h/2); // Step 7: Print the area of a trapezoid.
		
		// Step 8: End the main function.
		sc.close(); // Step 9: Close the Scanner object.
	}
}
