
// Importing necessary packages
import java.util.Scanner;

// Declaring variables
public class s693332680{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int x = scanner.nextInt();
		int a = scanner.nextInt();
		int b = scanner.nextInt();

		// Logic block to check if b is less than or equal to a
		if (b - a <= 0) {
			System.out.println("delicious");
		} else if (b - a <= x) {
			System.out.println("safe");
		} else {
			System.out.println("dangerous");
		}

		// End of code
		scanner.close();
	}
}