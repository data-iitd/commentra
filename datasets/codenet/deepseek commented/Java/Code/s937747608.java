import java.util.Scanner; // Importing Scanner class for input

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in); // Creating Scanner object
		int a = sc.nextInt(); // Reading first integer
		int b = sc.nextInt(); // Reading second integer
		int c = sc.nextInt(); // Reading third integer
		int d = sc.nextInt(); // Reading fourth integer
		
		// Comparing the products of the pairs of integers
		if(a*b >= c*d) {
			System.out.println(a*b); // Printing the larger product
		}else if(a*b <= c*d) {
			System.out.println(c*d); // Printing the larger product
		}
	}
}
