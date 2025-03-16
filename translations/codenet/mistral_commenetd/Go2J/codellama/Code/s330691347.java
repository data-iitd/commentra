
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize scanner for reading input from stdin
		Scanner sc = new Scanner(System.in);

		// Read number of data points N from the input
		int N = sc.nextInt();

		// Read number of queries L from the input
		int L = sc.nextInt();

		// Initialize a slice of Data type named s with capacity N
		Data[] s = new Data[N];

		// Read data points X from the input and store them in the slice s
		for (int i = 0; i < N; i++) {
			s[i] = new Data(sc.next());
		}

		// Print the number of data points N, number of queries L, and the slice s
		System.out.println(N + " " + L + " " + s);

		// Sort the slice s in ascending order based on X field
		sort(s);

		// Initialize an empty string ans to store the concatenated X values
		String ans = "";

		// Iterate through the slice s and concatenate X values to the string ans
		for (int i = 0; i < N; i++) {
			ans += s[i].X;
		}

		// Print the concatenated string ans to the console
		System.out.println(ans);
	}

	// Define a type Data to represent a single data point
	static class Data {
		String X;

		public Data(String X) {
			this.X = X;
		}
	}

	// Define a type Datas as a slice of Data
	static class Datas {
		Data[] data;

		public Datas(Data[] data) {
			this.data = data;
		}
	}

	// Implement Less method for Datas type to sort the slice based on X field
	static boolean less(Datas p, int i, int j) {
		return p.data[i].X.compareTo(p.data[j].X) < 0;
	}

	// Implement Swap method for Datas type to swap elements in the slice
	static void swap(Datas p, int i, int j) {
		Data temp = p.data[i];
		p.data[i] = p.data[j];
		p.data[j] = temp;
	}

	// Implement Len method for Datas type to get the length of the slice
	static int len(Datas p) {
		return p.data.length;
	}

	// Sort the slice s in ascending order based on X field
	static void sort(Data[] s) {
		int N = s.length;
		Datas p = new Datas(s);
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (less(p, i, j)) {
					swap(p, i, j);
				}
			}
		}
	}
}

