import java.util.Scanner; // Importing the Scanner class from the Java util package

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Creating a Scanner object named sc to read from the standard input

		int a, b, s; // Declaring three integer variables a, b, and s

		a = sc.nextInt(); // Reading an integer from the user and storing it in variable a
		b = sc.nextInt(); // Reading an integer from the user and storing it in variable b

		s = (a*b) - (a + b) + 1; // Calculating the value of s by multiplying a and b, subtracting the sum of a and b, and adding 1

		// The following line prints the value of s to the console
		System.out.println(s);
	}
}
