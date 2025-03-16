import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		// Read the integer n and the string s from the standard input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		
		// Convert the characters in s to their corresponding integer values
		// 'R' -> 0, 'G' -> 1, 'B' -> 2
		int[] ns = new int[n];
		for (int i = 0; i < n; i++) {
			switch (s.charAt(i)) {
			case 'R':
				ns[i] = 0;
				break;
			case 'G':
				ns[i] = 1;
				break;
			case 'B':
				ns[i] = 2;
				break;
			}
		}
		
		// Construct a cumulative count array rgb to keep track of the counts of each color up to each position
		int[][] rgb = new int[n+1][3];
		rgb[0][0] = rgb[0][1] = rgb[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			rgb[i][0] = rgb[i-1][0] + (ns[i-1] == 0? 1 : 0);
			rgb[i][1] = rgb[i-1][1] + (ns[i-1] == 1? 1 : 0);
			rgb[i][2] = rgb[i-1][2] + (ns[i-1] == 2? 1 : 0);
		}
		
		// Calculate the number of valid triplets (i, j, k) where ns[i]!= ns[j]!= ns[k] and ns[k] == tn
		// where tn is the third color different from ns[i] and ns[j]
		int sum = 0;
		for (int i = 0; i < n-2; i++) {
			for (int j = i + 1; j < n-1; j++) {
				if (ns[i]!= ns[j]) {
					int tn = 3 - ns[i] - ns[j];
					sum += rgb[n][tn] - rgb[j+1][tn];
					int k = 2*j - i;
					if (k < n && ns[k] == tn) {
						sum--;
					}
				}
			}
		}
		
		// Print the result
		System.out.println(sum);
	}
}

