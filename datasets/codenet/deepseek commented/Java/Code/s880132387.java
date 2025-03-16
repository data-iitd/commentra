import java.math.BigInteger;
import java.util.*;
import static java.lang.System.*;

class Main {
	public static Scanner sc = new Scanner(in);
	public static Random rand=new Random();

	public void run() {
		// Start an infinite loop to read input until both width and height are zero
		TCase:while(true){
			// Read the width (W) and height (H) of the map
			int W=sc.nextInt(),H=sc.nextInt();
			// If both width and height are zero, exit the loop
			if(W==0 && H==0)return;
			// Initialize the map as a 2D character array
			char[][] map=new char[H][W];

			// Read each row of the map from standard input and store it in the map array
			for(int h=0;h<H;h++){
				map[h]=sc.next().toCharArray();
			}

			// Initialize the dynamic programming table as a 2D BigInteger array
			BigInteger[][] dp=new BigInteger[H][W];

			// Fill the dynamic programming table based on the map and previous values
			for(int h=0;h<H;h++)for(int w=0;w<W;w++){
				BigInteger hprev=BigInteger.ZERO;
				// Check if there is a previous row and get its value
				if(h>=1){
					hprev=dp[h-1][w];
				}
				BigInteger wprev=BigInteger.ZERO;
				// Check if there is a previous column and get its value
				if(w>=1){
					wprev=dp[h][w-1];
				}
				// If the current cell contains a digit, compute the maximum value
				if(Character.isDigit(map[h][w])){
					BigInteger max;
					// Choose the maximum value between the previous row and column
					if(hprev.compareTo(wprev)>0){
						max=hprev;
					}else{
						max=wprev;
					}
					// Update the current cell with the computed value
					dp[h][w]=max.multiply(BigInteger.TEN).add(new BigInteger(map[h][w]+""));
				}else{
					// If the current cell does not contain a digit, set its value to zero
					dp[h][w]=BigInteger.ZERO;
				}
			}
			// Initialize the maximum value to zero
			BigInteger max=BigInteger.ZERO;
			// Find the maximum value in the dynamic programming table
			for(int h=0;h<H;h++)for(int w=0;w<W;w++){
				if(dp[h][w].compareTo(max)>0)max=dp[h][w];
			}
			// Print the maximum value found
			ln(max);
		}
	}
	public static void main(String[] args) {
		new Main().run();
	}

	public int[] nextIntArray(int n){
		int[] res=new int[n];
		for(int i=0;i<n;i++){
			res[i]=sc.nextInt();
		}
		return res;
	}
	public static void pr(Object o) {
		out.print(o);
	}
	public static void ln(Object o) {
		out.println(o);
	}
	public static void ln() {
		out.println();
	}
}
