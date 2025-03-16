import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare two integer variables to hold user input
		int a, b;
		
		// Read two integers from standard input
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		b = sc.nextInt();
		
		// Calculate and print the product of a and b, 
		// and also print the perimeter of a rectangle with sides a and b
		System.out.println(a*b);
		System.out.println((a+b)*2);
	}
}
