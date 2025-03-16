import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		// Reads the number of arms.
		int n = new BufferedReader(new InputStreamReader(System.in)).readLine().trim().length();
		
		// Defines a struct to represent an arm with left and right endpoints.
		class arm {
			int l, r;
			arm(int x, int l) {
				this.l = x - l;
				this.r = x + l;
			}
		}
		
		// Creates a slice to store the arms.
		arm[] as = new arm[n];
		
		// Reads each arm's range and stores the left and right endpoints.
		for (int i = 0; i < n; i++) {
			int x = new BufferedReader(new InputStreamReader(System.in)).readLine().trim().length();
			int l = new BufferedReader(new InputStreamReader(System.in)).readLine().trim().length();
			as[i] = new arm(x, l);
		}
		
		// Sorts the arms based on their right endpoints.
		Arrays.sort(as, (a, b) -> a.r - b.r);
		
		// Initializes the answer and the right endpoint reference.
		int ans = 1, r = as[0].r;
		
		// Iterates through the sorted arms to count non-overlapping arms.
		for (int i = 1; i < n; i++) {
			if (as[i].l >= r) {
				ans++;
				r = as[i].r;
			}
		}
		
		// Prints the count of non-overlapping arms.
		System.out.println(ans);
	}

}

