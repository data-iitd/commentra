
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	String[][] colorMtr; // 2D array to store the color information of the grid
	int h; // height of the grid
	int w; // width of the grid
	int k; // number of black cells required to form a pattern

	public static void main(String[] args) throws IOException {
		Main mainObj = new Main(); // create an instance of Main class
		mainObj.solve(); // call the solve method to find the answer
	}

	public void solve() throws IOException {
		FastScanner fs = new FastScanner(); // create an instance of FastScanner class to read input

		h = fs.nextInt(); // read the height of the grid
		w = fs.nextInt(); // read the width of the grid
		k = fs.nextInt(); // read the number of black cells required to form a pattern

		colorMtr = new String[h][]; // initialize the 2D array to store the color information of the grid
		for(int i = 0 ;i < h; i++) { // loop to read the rows of the grid
			colorMtr[i] = fs.next().split(""); // read each row as a string and split it by space to store in the array
		}

		int hPattern = pow(2, h); // calculate the number of possible patterns for the height
		int wPattern = pow(2, w); // calculate the number of possible patterns for the width

		int ans = 0; // initialize the answer variable to 0

		for(int i = 0; i < hPattern; i++) { // loop to check all possible patterns for the height
			for(int j = 0; j < wPattern; j++) { // loop to check all possible patterns for the width
				if(judge(i,j)) { // if the current pattern satisfies the condition, increment the answer
					ans++;
				}
			}
		}

		System.out.println(ans); // print the answer
	}

	boolean judge(int hPattern, int wPattern) { // method to check if the current pattern satisfies the condition

		int[] hBitArr = new int[h]; // initialize an array to store the binary representation of the height pattern
		int[] wBitArr = new int[w]; // initialize an array to store the binary representation of the width pattern

		for(int i = 0; i < h; i++) { // loop to convert the height pattern to binary
			if(((hPattern >> i) & 1) == 1) {
				hBitArr[i] = 1; // set the corresponding bit to 1 if the cell is present in the pattern
			}
		}

		for(int i = 0;i < w; i++) { // loop to convert the width pattern to binary
			if(((wPattern >> i) & 1) == 1) {
				wBitArr[i] = 1; // set the corresponding bit to 1 if the cell is present in the pattern
			}
		}

		int black = 0; // initialize the variable to count the number of black cells in the current pattern

		for(int i = 0; i < h; i++) { // loop to check each cell in the grid
			for(int j = 0; j < w; j++) {
				if(hBitArr[i] == 1 || wBitArr[j] == 1) { // if the current cell is part of the pattern, skip it
					continue;
				}

				if(colorMtr[i][j].equals("#")) { // if the current cell is black, increment the count
					black++;
				}
			}
		}

		if(black == k) { // if the number of black cells in the current pattern is equal to the required number, return true
			return true;
		}else { // otherwise, return false
			return false;
		}
	}

	public int pow(int base, int n) { // method to calculate the power of a number
		int retVal = 1;
		while (n > 0) {
			if ((n & 1) == 1) {
				retVal *= base; // multiply the base by itself if the current bit is 1
			}
			n >>= 1; // shift the bits to the right by one position
			base *= base; // multiply the base by itself for the next bit
		}
		return retVal;
	}
	

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