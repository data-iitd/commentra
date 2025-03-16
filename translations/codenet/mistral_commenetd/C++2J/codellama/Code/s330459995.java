import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Declare variables
		int W, H, x, y, r;

		// Create a Scanner object
		Scanner sc = new Scanner(System.in);

		// Read input values from user
		W = sc.nextInt();
		H = sc.nextInt();
		x = sc.nextInt();
		y = sc.nextInt();
		r = sc.nextInt();

		// Check if point is inside the rectangle or not
		if(x-r<0 || x+r>W || y-r<0 || y+r>H){
			// If point is outside the rectangle
			System.out.println("No");
		}
		else if(x-r>=0 && x+r<=W && y-r>=0 && y+r<=H){
			// If point is inside the rectangle
			System.out.println("Yes");
		}

		// Close the Scanner object
		sc.close();
	}
}
