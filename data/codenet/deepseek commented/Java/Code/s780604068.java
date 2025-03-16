import java.util.*;
public class Main {
	public static void main(String[] args){
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read the integer N which determines the size of the array
		int N = sc.nextInt();
		
		// Initialize an array 'map' to store N*2 integers
		int[] map = new int[N * 2];
		
		// Read N*2 integers into the 'map' array
		for (int i = 0; i < N * 2; i++) {
			map[i] = sc.nextInt();
		}
		
		// Sort the 'map' array to prepare for pairing
		Arrays.sort(map);
		
		// Initialize a variable 'max' to accumulate the sum of the minimums of each pair
		int max = 0;
		
		// Iterate through the sorted array in steps of 2, adding the minimum of each pair to 'max'
		for (int i = 0; i < N * 2; i+=2) {
			max += Math.min(map[i], map[i + 1]);
		}
		
		// Print the result which is the sum of the minimums of each pair
		System.out.println(max);
		
	}
}
