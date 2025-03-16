
import java.math.BigInteger;
import java.util.*;
import static java.lang.System.*;

class Main {
	// Initialize scanner for input
	public static Scanner sc = new Scanner(in);
	// Initialize random number generator
	public static Random rand=new Random();

	// Method to run the program
	public void run() {
		// Start an infinite loop to read input until EOF is reached
		TCase:while(true){
			// Read width and height of the grid from input
			int W = sc.nextInt();
			int H = sc.nextInt();

			// Check if the grid size is zero, if yes, exit the loop
			if(W==0 && H==0)return;

			// Initialize a 2D char array to store the grid
			char[][] map = new char[H][W];

			// Read each row of the grid and store it in the map array
			for(int h=0;h<H;h++){
				map[h] = sc.next().toCharArray();
			}

			// Initialize a 2D BigInteger array to store the DP values
			BigInteger[][] dp = new BigInteger[H][W];

			// Iterate through each cell in the grid and calculate its DP value
			for(int h=0;h<H;h++)for(int w=0;w<W;w++){
				// Initialize previous DP values for the current cell
				BigInteger hprev = BigInteger.ZERO;
				if(h>=1){
					hprev = dp[h-1][w]; // Previous DP value in the same column
				}
				BigInteger wprev = BigInteger.ZERO;
				if(w>=1){
					wprev = dp[h][w-1]; // Previous DP value in the previous row
				}

				// Calculate the DP value for the current cell based on previous DP values and the current character
				if(Character.isDigit(map[h][w])){
					BigInteger max;
					if(hprev.compareTo(wprev)>0){
						max = hprev; // Choose the maximum of previous DP values
					}else{
						max = wprev;
					}
					dp[h][w] = max.multiply(BigInteger.TEN).add(new BigInteger(map[h][w]+"")); // Multiply the maximum DP value with 10 and add the current digit
				}else{
					dp[h][w] = BigInteger.ZERO; // If the current cell is not a digit, its DP value is zero
				}
			}

			// Find the maximum DP value in the grid
			BigInteger max = BigInteger.ZERO;
			for(int h=0;h<H;h++)for(int w=0;w<W;w++){
				if(dp[h][w].compareTo(max)>0)max = dp[h][w]; // Update the maximum DP value if a new maximum is found
			}

			// Print the maximum DP value
			ln(max);
		}
	}
	// Main method to start the program
	public static void main(String[] args) {
		new Main().run();
	}

	// Helper method to read an array of integers from input
	public int[] nextIntArray(int n){
		int[] res=new int[n];
		for(int i=0;i<n;i++){
			res[i] = sc.nextInt();
		}
		return res;
	}
	// Helper method to print an object to the console
	public static void pr(Object o) {
		out.print(o);
	}
	// Helper method to print a newline to the console
	public static void ln(Object o) {
		out.println(o);
	}
	// Helper method to print a newline to the console without any argument
	public static void ln() {
		out.println();
	}
}

