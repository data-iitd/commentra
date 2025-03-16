
import java.util.Scanner; // Importing Scanner class for reading input from the console
class Main {
	static final int MAX; // Declaring a constant variable MAX with a value of 200000

	public static void main(String[] args) {
		int[] R; // Declaring an integer array R of size MAX
		Scanner in; // Declaring a Scanner object in for reading input from the console

		// Initializing the array R and Scanner object
		R = new int[MAX];
		in = new Scanner(System.in);

		int n; // Declaring an integer variable n for storing the number of elements in the array R

		// Reading the number of elements in the array R from the console
		n = in.nextInt();

		// Reading the elements of the array R from the console and storing them in the corresponding indices
		for(int i = 0;i<n;i++) {
			R[i] = in.nextInt();
		}

		int maxv = R[1]-R[0]; // Initializing maxv with the difference between the first two elements of the array R
		int minv = R[0]; // Initializing minv with the first element of the array R

		// Finding the maximum and minimum differences between consecutive elements of the array R
		for(int i = 1;i<n;i++){
			maxv = Math.max(maxv, R[i]-minv); // Updating maxv with the maximum difference found so far
			minv = Math.min(minv, R[i]); // Updating minv with the minimum element found so far
		}

		// Printing the maximum difference found between any two consecutive elements of the array R
		System.out.println(maxv);
	}
}