
import java.util.Scanner;

public class Average {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double a;
		double ave = 0;
		int i;

		for (i = 0; i < 5; i++) {
			System.out.print("Enter a number: ");
			a = sc.nextDouble();

			if (a <= 40) {
				ave += 40;
				System.out.println("Number " + (i + 1) + " is less than or equal to 40. Adding 40 to the average.");
			} else {
				ave += a;
				System.out.println("Number " + (i + 1) + " is greater than 40. Adding " + a + " to the average.");
			}
		}

		ave /= 5.0;
		System.out.println("The average of the 5 numbers is: " + ave);
	}
}

