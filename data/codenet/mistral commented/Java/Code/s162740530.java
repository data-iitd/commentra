
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in); // create a Scanner object to read input from the console

		int n = scanner.nextInt(); // read the first integer input and assign it to the variable n
		int m = scanner.nextInt(); // read the second integer input and assign it to the variable m

		int[] a = new int[m + 1]; // create an integer array a of size m+1 to store the input numbers
		int[] cnt = new int[n + 1]; // create an integer array cnt of size n+1 to store the count of numbers less than or equal to i

		cnt[0] = 1; // initialize the first element of the cnt array to 1
		final int MOD = 1000000007; // define a constant variable MOD for modular arithmetic

		// read the m numbers from the input and assign them to the array a
		for (int i = 1; i < a.length; i++) {
			a[i] = scanner.nextInt();
		}

		int num = 1; // initialize a variable num to 1

		if (m > 0) { // check if m is greater than 0
			if (a[1] == 1) { // check if the first number in the array a is equal to 1
				cnt[1] = 0; // if true, set the first element of the cnt array to 0
				if (num < m) { // if num is less than m, increment num
					num++;
				}
			} else {
				cnt[1] = 1; // if false, set the first element of the cnt array to 1
			}
		} else {
			cnt[1] = 1; // if m is non-positive, set the first element of the cnt array to 1
		}

		// calculate the count of numbers less than or equal to i for i from 2 to n
		for (int i = 2; i < cnt.length; i++) {
			cnt[i] = cnt[i - 2] + cnt[i - 1]; // calculate the count by adding the counts of the previous two elements
			cnt[i] %= MOD; // apply modular arithmetic to the count

			if (m > 0) { // check if m is greater than 0
				if (i == a[num]) { // check if the current index i is equal to the index of the current number in the array a
					cnt[i] = 0; // if true, set the count of the current index to 0
					if (num < m) { // if num is less than m, increment num
						num++;
					}
				}
			}

		}

		// print the final result, which is the count of numbers less than or equal to n
		System.out.println(cnt[n]);
		scanner.close(); // close the Scanner object to free up system resources
	}
}