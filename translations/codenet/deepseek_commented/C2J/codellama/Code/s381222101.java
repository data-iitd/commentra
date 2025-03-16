
// Step 1: Import the Scanner class to read input from the user.
import java.util.Scanner;

public class TrapezoidArea {
	
	// Step 2: Define the main function.
	public static void main(String[] args) {
		
		// Step 3: Declare three integer variables a, b, and h.
		int a, b, h;
		
		// Step 4: Create a Scanner object to read input from the user.
		Scanner sc = new Scanner(System.in);
		
		// Step 5: Read three integer values from the user and store them in a, b, and h.
		a = sc.nextInt();
		b = sc.nextInt();
		h = sc.nextInt();
		
		// Step 6: Calculate the area of a trapezoid using the formula (a+b)*h/2.
		int area = (a+b)*h/2;
		
		// Step 7: Print the area of the trapezoid.
		System.out.println(area);
		
		// Step 8: Close the Scanner object.
		sc.close();
	}
}

