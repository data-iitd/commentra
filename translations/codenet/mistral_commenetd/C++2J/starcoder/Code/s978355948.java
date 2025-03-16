
import java.util.*;

public class Main {

	public static void main(String[] args) {
		// Read input from stdin
		Scanner sc = new Scanner(System.in);

		// Read the number of elements in the vector L
		int N = sc.nextInt();

		// Read the sum X
		int X = sc.nextInt();

		// Create a vector L of size N to store the elements
		int[] L = new int[N];

		// Read elements of vector L from user input
		for(int i = 0; i < N; i++)
			L[i] = sc.nextInt();

		// Initialize variable i and d to zero
		int i = 0, d = 0;

		// Loop through the vector L until the sum d exceeds X
		for(; i < N && d <= X; i++){
			// Add the current element of vector L to the sum d
			d += L[i];
		}

		// Print the index of the last element in the vector L that was added to the sum d
		System.out.println(i+1);
	}
}

