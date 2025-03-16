
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(); // Initialize a new Scanner instance

		int n = sc.nextInt(); // Read an integer n from the standard input
		double ans = 0.0; // Initialize a variable ans to 0.0
		for (int i = 0; i < n; i++) { // Enter a loop that runs n times
			double tmp = 1 / sc.nextInt(); // Read an integer, convert it to a double, and divide 1 by this value
			ans += tmp; // Add this result to ans
		}
		System.out.println(1 / ans); // Calculate the reciprocal of ans and print it

	}

}

class Scanner {
	private BufferedReader r;
	private StringTokenizer st;

	public Scanner() {
		r = new BufferedReader(new InputStreamReader(System.in));
	}

	public String next() { // Read the next token from the input
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(r.readLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
	}

	public int nextInt() { // Read the next integer from the input
		return Integer.parseInt(next());
	}

	public double nextDouble() { // Read the next double from the input
		return Double.parseDouble(next());
	}

	public long nextLong() { // Read the next long from the input
		return Long.parseLong(next());
	}

	public String nextLine() { // Read the next line from the input
		String str = "";
		try {
			str = r.readLine();
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		return str;
	}

}

