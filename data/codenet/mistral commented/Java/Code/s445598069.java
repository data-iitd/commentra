
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader to read input from the console

		int n = Integer.parseInt(br.readLine()); // Read the number of elements in the array from the input

		String str[] = br.readLine().split(" "); // Read the array elements as strings and split them by space to create an array

		int s[] = new int[100010]; // Initialize an integer array of size 100010 to store the frequency of each element

		for (int i = 0; i < n; i++) { // Iterate through the array elements and increment the frequency of each element in the array
			s[Integer.parseInt(str[i])]++;
		}

		int dec = 0; // Initialize a variable to store the number of decrements

		for (int i = 0; i < s.length; i++) { // Iterate through the array and process each element based on its frequency
			if (s[i] != 0) { // If the frequency of an element is not zero
				if (s[i] % 2 == 0) { // If the frequency is even
					s[i] = 2; // Set the frequency to 2 in the result array
				} else { // If the frequency is odd
					s[i] = 1; // Set the frequency to 1 in the result array
					dec++; // Increment the number of decrements as there is an odd frequency element
				}
			}
		}

		int one = 0; // Initialize two variables to store the count of 1's and 2's in the result array
		int two = 0;

		for (int i = 0; i < s.length; i++) { // Iterate through the array and count the number of 1's and 2's in the result array
			if (s[i] == 2) {
				two++;
			} else if (s[i] == 1) {
				one++;
			}
		}

		if (two % 2 != 0) { // Check if the number of 2's in the result array is odd
			one--; // Decrement the count of 1's if the number of 2's is odd
		}

		System.out.println(two + one); // Print the sum of the number of 2's and the adjusted count of 1's as the output.
	}

}