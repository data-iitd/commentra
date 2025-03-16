
import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		// Read the number of symbols and the input string from standard input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		char[] s = new char[n + 1];
		s[0] ='';
		for (int i = 1; i <= n; ++i)
			s[i] = sc.next().charAt(0);

		// Initialize the first element of f and g arrays
		long[] f = new long[n + 1];
		int[] g = new int[n + 1];
		f[0] = 0;
		g[0] = 0;

		// Process each symbol in the input string
		for (int i = 1; i <= n; ++i) {
			// Update the current element of f array based on the current symbol
			if (s[i] == '+' || s[i] == '-')
				f[i] = f[i - 1] + (s[i] == '+'? 1 : -1) * (long) Math.pow(B, g[i] = g[i - 1]);
			// If the current symbol is not an operator, just copy the previous value of f to the current position
			else
				f[i] = f[i - 1], g[i] = g[i - 1] + (s[i] == '<'? -1 : 1);
		}

		// Calculate the final result
		long cnt = 0;
		Map<Long, Long> map = new HashMap<Long, Long>();
		for (int i = n; i; --i) {
			map.put(f[i], map.getOrDefault(f[i], 0l) + 1); // Increment the count of the intermediate result in the map
			cnt += map.getOrDefault(f[n] * (long) Math.pow(B, g[i - 1]) + f[i - 1], 0l); // Add the contribution of the current symbol to the final result
		}

		System.out.println(cnt); // Print the final result to standard output
	}
}

