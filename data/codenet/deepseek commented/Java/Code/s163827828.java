
import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next()); // Read the number of strings
		String s[] = new String[N]; // Initialize an array of strings with size N
		int a_num = 0; // Counter to count strings ending with 'A'
		int b_num = 0; // Counter to count strings starting with 'B'
		boolean flag = true; // Flag to check if there is any string that starts with 'B' and ends with 'A'
		int ans = 0; // Counter to count occurrences of the substring "AB"
		
		// Loop through each string in the array
		for(int i = 0; i < N; i++) {
			s[i] = sc.next(); // Read the string
			if(s[i].substring(0, 1).equals("B")) {
				b_num++; // Increment b_num if the string starts with 'B'
			}
			if(s[i].substring(s[i].length() - 1, s[i].length()).equals("A")){
				a_num++; // Increment a_num if the string ends with 'A'
			}
			if(s[i].substring(0, 1).equals("B") || s[i].substring(s[i].length() - 1, s[i].length()).equals("A")) {
				if(!(s[i].substring(0, 1).equals("B") && s[i].substring(s[i].length() - 1, s[i].length()).equals("A"))) {
					flag = false; // Set flag to false if the string starts with 'B' and ends with 'A'
				}
			}
			// Count occurrences of the substring "AB" in the string
			for(int j = 0; j < s[i].length() - 1; j++) {
				if(s[i].substring(j, j + 2).equals("AB")) ans++;
			}
		}
		
		// Calculate the final answer
		ans += Math.min(a_num, b_num); // Add the minimum of a_num and b_num to ans
		if(Math.min(a_num, b_num) != 0 && flag) {
			ans--; // Decrement ans by 1 if the minimum of a_num and b_num is not zero and flag is true
		}
		
		// Print the result
		System.out.println(ans);
	}
}

