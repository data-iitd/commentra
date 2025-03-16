import java.util.Scanner; // Importing the Scanner class for reading input from the console

public class Main {
	public static void main(String[] args) { // Main method where the execution of the program starts
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console
		String s = sc.next(); // Reading a string input from the console and storing it in the 's' variable
		int n = s.length(); // Determining the length of the string 's' and storing it in the 'n' variable
		long ans = 0; // Initializing an accumulator variable 'ans' to store the final result

		for(int mask = 0 ; mask < 1<<(n - 1) ; mask++) { // Starting a loop that runs 'n-1' times
			// The following block of code generates all possible substrings of 's' by iterating through all the binary masks

			long sum = 0; // Initializing a variable 'sum' to store the sum of digits in the current substring
			String x = "" + s.charAt(0); // Creating an empty string 'x' and appending the first character of 's' to it

			for(int i = 0 ; i < n - 1 ; i++) { // Looping through the remaining characters of 's'
				if((mask&(1<<i)) >= 1) { // Checking if the current bit in the binary mask is set (1)
					// If the bit is set, append the current character of 's' to 'x' with a '+' sign
					x += "+" + s.charAt(i + 1);
				} else {
					// If the bit is not set, just append the current character of 's' to 'x'
					x += s.charAt(i + 1);
				}
			}
			// The following block of code processes the generated substring 'x' and calculates its sum

			String[] split = x.split("\\+"); // Splitting the string 'x' into an array of substrings using '+' as a delimiter
			for(int i = 0 ; i < split.length ; i++) { // Looping through each substring in the array
				sum += Long.valueOf(split[i]); // Converting each substring to a long value and adding it to the 'sum' variable
			}
			ans += sum; // Adding the sum of the current substring to the accumulator variable 'ans'
		}
		System.out.println(ans); // Printing the final result
	}
}
