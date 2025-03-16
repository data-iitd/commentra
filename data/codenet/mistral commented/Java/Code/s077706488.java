
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize scanner to read input from the console
		Scanner stdIn = new Scanner(System.in);

		// Read the number of elements in the array from the input
		int N = stdIn.nextInt();

		// Read the value of X from the input
		int X = stdIn.nextInt();

		// Initialize an integer array m of size N
		int[] m = new int[N];

		// Read the first element of the array from the input and subtract it from X
		m[0] = stdIn.nextInt();
		X -= m[0];

		// Initialize min as the first element of the array
		int min = m[0];

		// Iterate through the array from the second element to the last
		for(int i = 1; i < N; i++) {
			// Read the next element of the array from the input and subtract it from X
			m[i] = stdIn.nextInt();
			X -= m[i];

			// Update min if the current element is smaller than the previous minimum
			if(m[i] < min) {
				min = m[i];
			}
		}

		// Print the result: the number of elements in the array plus the quotient of X by the minimum element
		System.out.println(N+X/min);

	}

}