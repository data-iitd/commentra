package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read number of data points N from the input
		int N = sc.nextInt();

		// Read number of queries L from the input
		int L = sc.nextInt();

		// Initialize a slice of Data type named s with capacity N
		Data[] s = new Data[N];

		// Read data points X from the input and store them in the slice s
		for (int i = 0; i < N; i++) {
			s[i] = new Data();
			s[i].X = sc.next();
		}

		// Print the number of data points N, number of queries L, and the slice s
		System.out.println(N + " " + L + " " + s);

		// Sort the slice s in ascending order based on X field
		sort(s);

		// Initialize an empty string ans to store the concatenated X values
		String ans = "";

		// Iterate through the slice s and concatenate X values to the string ans
		for (int i = 0; i < N; i++) {
			ans = ans + s[i].X;
		}

		// Print the concatenated string ans to the console
		System.out.println(ans);
	}

	// Define a type Data to represent a single data point
	public static class Data {
		public String X;
	}

	// Sort the slice s in ascending order based on X field
	public static void sort(Data[] s) {
		for (int i = 0; i < s.length; i++) {
			for (int j = i + 1; j < s.length; j++) {
				if (s[i].X.compareTo(s[j].X) > 0) {
					Data temp = s[i];
					s[i] = s[j];
					s[j] = temp;
				}
			}
		}
	}
}

