import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);  // Create a Scanner object to read input from stdin
		
		int n = sc.nextInt();  // Read the value of n from stdin
		int d = sc.nextInt();  // Read the value of d from stdin
		
		int[][] point = new int[n+1][d+1];  // Create a 2D array to store the points with dimensions (n+1) x (d+1)
		
		// Nested loop to read the coordinates of each point from the standard input
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= d; j++){
				point[i][j] = sc.nextInt();
			}
		}
		
		int count = 0;  // Initialize a counter to zero to count the number of integer distances
		
		// Nested loop to calculate the Euclidean distance between each pair of points
		for (int i = 1; i <= n-1; i++){
			for (int j = i+1; j <= n; j++){
				
				int sum = 0;  // Initialize a variable to store the sum of squared differences
				for (int k = 1; k <= d; k++){
					sum = sum + (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
				}
				double kyori = Math.sqrt(sum);  // Compute the square root of the sum to get the distance
				
				// Check if the distance is an integer by comparing ceil and floor of the distance
				if (Math.ceil(kyori) == Math.floor(kyori)){
					count++;  // Increment the counter if the distance is an integer
				}
			}
		}
		
		System.out.println(count);  // Print the final count of integer distances
	}
}

