import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	// 2D array to store the color matrix
	String[][] colorMtr;
	// Height and width of the matrix
	int h;
	int w;
	// Target number of black cells
	int k;

	public static void main(String[] args) throws IOException {
		// Create an instance of Main and invoke the solve method
		Main mainObj = new Main();
		mainObj.solve();
	}

	public void solve() throws IOException {
		// Initialize FastScanner to read input
		FastScanner fs = new FastScanner();
		
		// Read height, width, and target number of black cells
		h = fs.nextInt();
		w = fs.nextInt();
		k = fs.nextInt();
		
		// Initialize the color matrix based on the height
		colorMtr = new String[h][];
		for(int i = 0; i < h; i++) {
			// Read each row of the matrix and split it into characters
			colorMtr[i] = fs.next().split("");
		}
		
		// Calculate the number of possible patterns for height and width
		int hPattern = pow(2, h);
		int wPattern = pow(2, w);
		
		// Initialize the answer counter
		int ans = 0;
		
		// Iterate through all possible height and width patterns
		for(int i = 0; i < hPattern; i++) {
			for(int j = 0; j < wPattern; j++) {
				// Check if the current pattern meets the condition
				if(judge(i, j)) {
					ans++; // Increment the answer if the condition is met
				}
			}
		}
		
		// Output the final count of valid patterns
		System.out.println(ans);
	}
	
	// Method to judge if a given height and width pattern is valid
	boolean judge(int hPattern, int wPattern) {
		
		// Arrays to track which rows and columns are included in the pattern
		int[] hBitArr = new int[h];
		int[] wBitArr = new int[w];
		
		// Fill the height bit array based on the height pattern
		for(int i = 0; i < h; i++) {
			if(((hPattern >> i) & 1) == 1) {
				hBitArr[i] = 1; // Mark the row as included
			}
		}
		
		// Fill the width bit array based on the width pattern
		for(int i = 0; i < w; i++) {
			if(((wPattern >> i) & 1) == 1) {
				wBitArr[i] = 1; // Mark the column as included
			}
		}
		
		// Counter for black cells that are not included in the pattern
		int black = 0;
		
		// Count the number of black cells that are not excluded by the pattern
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(hBitArr[i] == 1 || wBitArr[j] == 1) {
					continue; // Skip if the row or column is included in the pattern
				}
				
				// Increment the black cell counter if the cell is black
				if(colorMtr[i][j].equals("#")) {
					black++;
				}
			}
		}
		
		// Return true if the count of black cells matches the target k
		return black == k;
	}

	// Method to calculate power of a base raised to an exponent
	public int pow(int base, int n) {
		int retVal = 1;
		// Efficiently calculate base^n using bitwise operations
		while (n > 0) {
			if ((n & 1) == 1) {
				retVal *= base; // Multiply if the current bit is 1
			}
			n >>= 1; // Right shift n to process the next bit
			base *= base; // Square the base
		}
		return retVal; // Return the computed power
	}
	
	// FastScanner class to handle input efficiently
	public class FastScanner {

		BufferedReader reader; // BufferedReader for input
		private StringTokenizer st; // Tokenizer for parsing input

		// Constructor to initialize the FastScanner
		public FastScanner() {
			st = null;
			reader = new BufferedReader(new InputStreamReader(System.in));
		}

		// Method to read the next token as a String
		public String next() throws IOException {
			if (st == null || !st.hasMoreElements()) {
				st = new StringTokenizer(reader.readLine()); // Read a new line if needed
			}
			return st.nextToken(); // Return the next token
		}

		// Method to read the next line as a String
		public String nextLine() throws IOException {
			st = null; // Reset the tokenizer
			return reader.readLine(); // Return the entire line
		}

		// Method to read the next token as an integer
		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next()); // Parse and return the next token as an integer
		}

		// Method to read the next token as a long
		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next()); // Parse and return the next token as a long
		}

		// Method to read an array of integers
		public int[] nextIntArr(int n) throws NumberFormatException, IOException {
			int[] retArr = new int[n];
			for (int i = 0; i < n; i++) {
				retArr[i] = nextInt(); // Fill the array with integers
			}
			return retArr; // Return the filled array
		}

		// Method to read an array of longs
		public long[] nextLongArr(int n) throws NumberFormatException, IOException {
			long[] retArr = new long[n];
			for (int i = 0; i < n; i++) {
				retArr[i] = nextLong(); // Fill the array with longs
			}
			return retArr; // Return the filled array
		}

		// Method to close the BufferedReader
		public void close() throws IOException {
			reader.close(); // Close the reader
		}
	}
}
