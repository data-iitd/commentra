
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables to store the coordinates
		int x1, y1, x2, y2;
		
		// Read four integers from standard input
		Scanner in = new Scanner(System.in);
		x1 = in.nextInt();
		y1 = in.nextInt();
		x2 = in.nextInt();
		y2 = in.nextInt();
		
		// Calculate the differences between the coordinates
		int a = x2 - x1;
		int b = y2 - y1;
		
		// Calculate the new coordinates based on the differences
		int x3 = x2 - b;
		int y3 = y2 + a;
		int x4 = x1 - b;
		int y4 = y1 + a;
		
		// Print the new coordinates to standard output
		System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
	}

}

