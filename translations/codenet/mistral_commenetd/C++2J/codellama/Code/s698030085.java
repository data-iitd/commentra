import java.util.Scanner; // We import the Scanner class to read user input

public class Main { // We define a public class named Main
	public static void main(String[] args) { // The main function is the entry point of the program
		Scanner sc = new Scanner(System.in); // We create a new Scanner object to read user input
		long a = sc.nextLong(); // We read the first long integer and store it in a
		long b = sc.nextLong(); // We read the second long integer and store it in b

		if ((a + b) % 2 == 0) { // We check if the sum of a and b is even
			// If the sum is even, we print the result by dividing it by 2
			System.out.println((a + b) / 2);
		} else { // If the sum is odd, we print "IMPOSSIBLE"
			System.out.println("IMPOSSIBLE");
		}
	}
}

