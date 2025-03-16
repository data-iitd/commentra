
// Import the Scanner class for input
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// Create a Scanner object for input
		Scanner in = new Scanner(System.in);
		
		// Declare variables for input and digit
		int n, t;
		
		// Declare an array to store the state of segments
		boolean[] st = new boolean[7];
		
		// Read input until a negative number is encountered
		while(in.hasNextInt()) {
			n = in.nextInt(); // Read the input
			
			// Initialize segment states to 0
			for(int i=0; i<7; i++) st[i] = false;
			
			// Process each digit input
			for(int i=0; i<n; i++) {
				t = in.nextInt(); // Read the digit
				char[] ans = new char[8]; // Initialize answer array to store segment states
				
				// Determine the segment states based on the input digit
				for(int i=0; i<7; i++) {
					// Calculate the current segment state and store it in ans
					ans[i] = st[i] ^ seg[t][i] ? '1' : '0'; 
					st[i] = seg[t][i]; // Update the current segment state
				}
				System.out.println(ans); // Output the segment states for the current digit
			}
		}
		
		in.close(); // Close the Scanner object
	}
	
	// Segment representation for digits 0-9
	static boolean[][] seg = {
		{false,true,true,true,true,true,true}, // 0
		{false,false,false,false,true,true,false}, // 1
		{true,false,true,true,false,true,true}, // 2
		{true,false,false,true,true,true,true}, // 3
		{true,true,false,false,true,true,false}, // 4
		{true,true,false,true,true,false,true}, // 5
		{true,true,true,true,true,false,true}, // 6
		{false,true,false,false,true,true,true}, // 7
		{true,true,true,true,true,true,true}, // 8
		{true,true,false,true,true,true,true}  // 9
	};
}

