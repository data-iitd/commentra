
import java.io.*;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException{ 
		// Step 1: Reading Input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String sc = br.readLine();
		int n = Integer.parseInt(sc); // Read the number of cards
		String[] str = new String[n]; // Create an array to store card specifications
		for (int i = 0; i < n; i++) {
			str[i] = br.readLine(); // Read each card specification and store it in the array
		}

		// Step 2: Define the suits
		String[] mark = {"S", "H", "C", "D"}; // Array containing the four suits

		// Step 3: Generate and check for missing cards
		for (String ma : mark) { // Iterate through each suit
			for (int i = 1; i <= 13; i++) { // Iterate through numbers 1 to 13
				String s = Integer.toString(i); // Convert the number to a string
				String st = ma + " " + s; // Create the card string in the format "suit number"
				if (Arrays.asList(str).contains(st)) { // Check if the card is present in the input
					continue; // If present, move to the next card
				} else {
					System.out.println(st); // If not present, print the missing card
				}
			}
		}
	}
}

