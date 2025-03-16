package main;

import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) {
		try {
			// Read input values for n and x
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			String[] tokens = line.split(" ");
			int n = Integer.parseInt(tokens[0]);
			int x = Integer.parseInt(tokens[1]);
			int[] A = new int[n];
			for (int i = 0; i < n; i++) {
				line = br.readLine();
				A[i] = Integer.parseInt(line);
			}

			// Sort the array A
			Arrays.sort(A);

			// Initialize answer variable
			int ans = 0;
			// Count how many elements can be taken from A without exceeding x
			for (int i = 0; i < n; i++) {
				if (x >= A[i]) {
					ans++;
					x -= A[i];
				} else {
					break;
				}
			}
			// Adjust answer if all elements are taken and there is still remaining x
			if (ans == n && x > 0) {
				ans--;
			}
			// Print the final answer
			System.out.println(ans);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

