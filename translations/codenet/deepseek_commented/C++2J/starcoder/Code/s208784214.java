import java.util.*;

public class Main {
	public static void main(String[] args) {
		// Step 1: Read input values
		// We read two integer values from the standard input and store them in variables N and A.
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A = sc.nextInt();
		
		// Step 2: Perform the required operation
		// We check if the remainder of N divided by 500 is less than or equal to A.
		// If the condition is true, we print "Yes"; otherwise, we print "No".
		System.out.println((N % 500 <= A? "Yes" : "No"));
		
		// Step 3: Return from the main function
		// We return 0 to indicate successful execution of the program.
		return 0;
	}
}
