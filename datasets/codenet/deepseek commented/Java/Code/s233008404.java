import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	// Matrix to store the colors of the cells
	String[][] colorMtr;
	// Height of the matrix
	int h;
	// Width of the matrix
	int w;
	// Number of black cells required
	int k;

	// Main method to execute the program
	public static void main(String[] args) throws IOException {
		Main mainObj = new Main();
		mainObj.solve();
	}

	// Method to solve the problem
	public void solve() throws IOException {
		FastScanner fs = new FastScanner();
		
		// Read the dimensions of the matrix and the number of black cells required
		h = fs.nextInt();
		w = fs.nextInt();
		k = fs.nextInt();
		
		// Initialize the matrix with the colors of the cells
		colorMtr = new String[h][];
		for(int i = 0 ;i < h; i++) {
			colorMtr[i] = fs.next().split("");
		}
		
		// Calculate the number of possible patterns for rows and columns
		int hPattern = pow(2, h);
		int wPattern = pow(2, w);
		
		// Initialize the answer counter
		int ans = 0;
		
		// Iterate over all possible patterns and count valid ones
		for(int i = 0; i < hPattern; i++) {
			for(int j = 0; j < wPattern; j++) {
				if(judge(i,j)) {
					ans++;
				}
			}
		}
		
		// Print the count of valid patterns
		System.out.println(ans);
	}
	
	// Method to determine if a given pattern results in exactly k black cells
	boolean judge(int hPattern, int wPattern) {
		
		// Arrays to store the pattern for rows and columns
		int[] hBitArr = new int[h];
		int[] wBitArr = new int[w];
		
		// Convert the pattern to row and column arrays
		for(int i = 0; i < h; i++) {
			if(((hPattern >> i) & 1) == 1) {
				hBitArr[i] = 1;
			}
		}
		
		for(int i = 0;i < w; i++) {
			if(((wPattern >> i) & 1) == 1) {
				wBitArr[i] = 1;
			}
		}
		
		// Count the number of black cells in the remaining cells
		int black = 0;
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++) {
				if(hBitArr[i] == 1 || wBitArr[j] == 1) {
					continue;
				}
				
				if(colorMtr[i][j].equals("#")) {
					black++;
				}
			}
		}
		
		// Check if the count of black cells is exactly k
		if(black == k) {
			return true;
		}else {
			return false;
		}
	}

	// Method to calculate the power of a base to a given exponent
	public int pow(int base, int n) {
		int retVal = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				retVal *= base;
			}
			n >>= 1;
			base *= base;
		}
		return retVal;
	}
	
	// FastScanner class to read input efficiently
	public class FastScanner {

		BufferedReader reader;
		private StringTokenizer st;

		public FastScanner() {
			st = null;
			reader = new BufferedReader(new InputStreamReader(System.in));
		}

		public String next() throws IOException {
			if (st == null || !st.hasMoreElements()) {
				st = new StringTokenizer(reader.readLine());
			}
			return st.nextToken();
		}

		public String nextLine() throws IOException {
			st = null;
			String readLine = null;
			readLine = reader.readLine();
			return readLine;
		}

		public int nextInt() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public int[] nextIntArr(int n) throws NumberFormatException, IOException {
			int[] retArr = new int[n];
			for (int i = 0; i < n; i++) {
				retArr[i] = nextInt();
			}
			return retArr;
		}

		public long[] nextLongArr(int n) throws NumberFormatException, IOException {
			long[] retArr = new long[n];
			for (int i = 0; i < n; i++) {
				retArr[i] = nextLong();
			}
			return retArr;
		}

		public void close() throws IOException {
			reader.close();
		}
	}

}
