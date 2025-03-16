
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Importing Scanner: The Scanner class from java.util package is imported to read input from the user.
		Scanner sc = new Scanner(System.in);
		
		// Reading an Integer Input: The nextInt() method of the Scanner object reads an integer input from the user.
		int r = sc.nextInt();
		
		// Calculating the Area of a Circle: The area of a circle is calculated using the formula 3 * r * r.
		System.out.println(3 * r * r);
	}
}

