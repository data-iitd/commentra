import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if (n == 0) {
				break;
			}
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = in.nextInt();
			}
			int ans = n;
			for (int i = 0; i < n - 4; i++) {
				int[] count = new int[3];
				for (int j = i; j < i + 4; j++) {
					if (a[j] - 1 >= 0) {
						count[a[j] - 1]++;
					}
				}
				int color = 0;
				for (int j = 0; j < 3; j++) {
					if (count[j] >= 3) {
						color = j + 1;
						break;
					}
				}
				if (color!= 0) {
					for (int j = i; j < i + 4; j++) {
						int buf;
						buf = a[j];
						a[j] = color;
						ans = Math.min(ans, Chain(a, n));
						a[j] = buf;
					}
				}
			}
			System.out.println(ans);
		}
	}

	public static int Chain(int[] a, int n) {
		int i, j;
		int count = 0; // To count the length of the chain
		int color = 0; // To store the color of the chain
		int[] a2 = new int[10000]; // Temporary array to hold the modified sequence

		// Copy the original array to a temporary array
		for (i = 0; i < n; i++) {
			a2[i] = a[i];
		}

		// Iterate through the array to find and remove chains of four or more elements
		for (i = 0; i < n - 4; i++) {
			if (a2[i]!= 0 && a2[i] == a2[i + 1] && a2[i] == a2[i + 2] && a2[i] == a2[i + 3]) {
				// Debugging output to show the array before removal
				/*
				System.out.println("-----");
				for (j = 0; j < n; j++) {
					System.out.println(a2[j]);
				}
				System.out.println("-----");
				*/

				count = 0;
				color = a2[i];

				// Remove the chain by setting all elements to 0
				for (j = i; a2[j] == color; j++) {
					a2[j] = 0;
					count++;
				}

				// Shift the remaining elements to fill the gap left by the removed chain
				for (j = 0; i + j + count < 10000; j++) {
					a2[i + j] = a2[i + j + count];
					a2[i + j + count] = 0;
				}

				// Debugging output to show the array after removal
				/*
				System.out.println("-----");
				for (j = 0; j < n; j++) {
					System.out.println(a2[j]);
				}
				System.out.println("-----");
				*/

				// Reset the index to start checking from the beginning
				i = 0;
			}

		}

		count = 0;
		while (a2[count]!= 0) {
			count++;
		}

		// Check if the remaining sequence is a chain of four or more elements
		if (count == 4 && a2[0] == a2[1] && a2[0] == a2[2] && a2[0] == a2[3]) {
			return 0;
		}

		return count;
	}
}

