import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) {
		// Read two integers from the standard input
		String[] s = readLine().split(" ");
		// Parse the first integer
		int a = Integer.parseInt(s[0]);
		// Parse the second integer
		int b = Integer.parseInt(s[1]);
		// Check if the second integer is divisible by the first integer
		if(b%a==0){
			// If divisible, print the sum of the two integers
			System.out.println(a+b);
		}else{
			// If not divisible, print the difference between the two integers
			System.out.println(b-a);
		}
		// Return from the main method
		return;
	}

	private static String readLine(){
		// Create a BufferedReader to read input from the standard input stream
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		try{
			// Read a line from the standard input
			return reader.readLine();
		}catch(Exception e){
			// If an exception occurs, return the exception message
			return e.getMessage();
		}
	}
}