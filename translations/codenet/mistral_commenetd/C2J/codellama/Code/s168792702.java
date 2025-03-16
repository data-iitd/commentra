
public class Main {
	public static void main(String[] args) {
		// Declare three integer variables: a, b, and c
		int a, b, c;

		// Use the Scanner class to read three integers from the standard input and store them in variables a, b, and c
		Scanner scanner = new Scanner(System.in);
		a = scanner.nextInt();
		b = scanner.nextInt();
		c = scanner.nextInt();

		// Check if the condition a < b and b < c is true. If it is, print "Yes" to the standard output using the System.out.println function. Otherwise, print "No"
		if (a < b && b < c) {
			System.out.println("Yes"); // If the condition is true, print "Yes"
		} else {
			System.out.println("No"); // If the condition is false, print "No"
		}
	}
}

