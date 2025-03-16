
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// Create a Scanner object to read input from the standard console
		Scanner stdIn = new Scanner(System.in);
		
		// Read the number of elements (N) and the initial value of X
		int N = stdIn.nextInt();
		int X = stdIn.nextInt();
		
		// Initialize an array of size N to store the elements
		int[] m = new int[N];
		
		// Read the first element of the array and subtract it from X
		m[0] = stdIn.nextInt();
		X -= m[0];
		
		// Initialize the minimum value with the first element of the array
		int min = m[0];
		
		// Loop through the rest of the array to read elements and update X and find the minimum value
		for(int i = 1; i < N; i++) {
			m[i] = stdIn.nextInt();
			X -= m[i];
			if(m[i] < min) {
				min = m[i];
			}
		}
		
		// Calculate and print the result based on the remaining value of X and the minimum value in the array
		System.out.println(N + X / min);
	}
}

