import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare variables for the number of elements (n), the threshold value (x), and a slice to hold the integers (l)
		int n, x;
		int[] l;
		
		// Read the number of elements (n) from standard input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		// Read the threshold value (x) from standard input
		x = sc.nextInt();
		sc.close();
		
		// Initialize the slice l
		l = new int[n];
		
		// Loop to read n integers from standard input and append them to the slice l
		for (int i = 0; i < n; i++) {
			int tmpL;
			// Read each integer and store it in tmpL
			Scanner sc2 = new Scanner(System.in);
			tmpL = sc2.nextInt();
			sc2.close();
			// Append the read integer to the slice l
			l[i] = tmpL;
		}
		
		// Initialize variables to keep track of the cumulative sum (tmpSum) and the result (rs)
		int tmpSum = 0;
		int rs = 0;
		
		// Loop through the slice l to calculate the cumulative sum and determine the result
		for (int i = 0; i < n; i++) {
			// Add the current value to the cumulative sum
			tmpSum += l[i];
			
			// Check if the index exceeds the number of elements
			if (i >= n) {
				rs = n; // Set result to n if index exceeds n
				break;
			}
			
			// If the cumulative sum is less than or equal to x, update the result
			if (tmpSum <= x) {
				rs = i + 2; // Update result to the current index + 2
			} else if (tmpSum > x) {
				break; // Exit the loop if the cumulative sum exceeds x
			}
		}
		
		// Print the final result
		System.out.println(rs);
	}
}

