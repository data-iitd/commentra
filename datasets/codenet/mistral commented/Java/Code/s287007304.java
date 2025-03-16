import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		// Initialize an empty string array to store user input
		String[] s = new String[2];

		// Read user input as a single line and split it into two parts using space as delimiter
		String inputLine = readLine();
		s = inputLine.split(" ");

		// Parse the first two elements of the string array as integers 'a' and 'b'
		int a = Integer.parseInt(s[0]);
		int b = Integer.parseInt(s[1]);

		// Check if 'b' is divisible by 'a'
		if(b%a == 0){
			// If yes, print the sum of 'a' and 'b'
			System.out.println(a + b);
		}else{
			// If not, print the difference between 'b' and 'a'
			System.out.println(b - a);
		}

		// Return from the main method
		return;
	}

	// A private helper method to read a single line of user input
	private static String readLine(){
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try{
			// Read a single line of user input and return it as a string
			return reader.readLine();
		}catch(Exception e){
			// If an error occurs during input, print the error message and return an empty string
			System.out.println("Error: " + e.getMessage());
			return "";
		}
	}
}