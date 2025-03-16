
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);  // Create a Scanner object
		
		int n, i, j, q, x[], y[], sum = 0;  // Declare variables
		
		n = sc.nextInt();  // Read the number of elements
		
		x = new int[n];  // Create an array of size n
		
		for(i = 0; i < n; i++) {
			x[i] = sc.nextInt();  // Read the elements of array x
		}
		
		q = sc.nextInt();  // Read the number of queries
		
		y = new int[q];  // Create an array of size q
		
		for(i = 0; i < q; i++) {
			y[i] = sc.nextInt();  // Read the elements of array y
		}
		
		for(i = 0; i < q; i++) {  // For each query
			for(j = 0; j < n; j++) {  // Check each element in array x
				if(y[i] == x[j]) {  // If the query matches an element in x
					sum = sum + 1;  // Increment the sum
					break;  // Break out of the inner loop
				}
			}
		}
		
		System.out.println(sum);  // Print the sum of matches
		
		sc.close();  // Close the Scanner object
		
	}

}

