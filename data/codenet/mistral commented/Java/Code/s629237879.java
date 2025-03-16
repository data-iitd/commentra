
import java.io.*;
import java.util.Arrays;

public class Main {
	// Initialize BufferedReader to read input from the console
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// Read the first line which contains the number of strings to be read
		String sc = br.readLine();
		// Parse the input string to an integer representing the number of strings
		int n = Integer.parseInt(sc);
		// Create an array of strings with the given size
		String[] str = new String[n];
		// Read each line and store it in the corresponding index of the string array
		for (int i =0;i<n ;i++ ) {
			str[i] = br.readLine();
		}
		// Define an array containing the four marks: S, H, C, D
		String[] mark = {"S","H","C","D"};
		// Iterate through each mark
		for (String ma : mark) {
			// Initialize a loop counter for the cards from 1 to 13
			for (int i = 1; i<=13 ;i++ ) {
				// Convert the card number to a string
				String s = Integer.toString(i);
				// Combine the mark and the card number to form a string
				String st = ma + " " + s;
				// Check if the string is already present in the input array
				if (Arrays.asList(str).contains(st)) {
					// If present, skip to the next iteration of the outer loop
					continue;
				}else{
					// If not present, print the string to the console
					System.out.println(st);
				}
			}
		}
	}
}

