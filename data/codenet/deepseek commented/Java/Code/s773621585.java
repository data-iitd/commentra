
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args)
	{
		// Initialize a HashMap to store key-value pairs
		HashMap<String, String> map = new HashMap<String, String>();
		
		// Create a Scanner object to read input from the user
		Scanner sc = new Scanner(System.in);
		
		// Read the number of entries from the user
		int n = sc.nextInt();
		
		// Read the first line (which is a newline character) and discard it
		String str= sc.nextLine();
		
		// Loop to read n lines of input and store each line as a key in the HashMap
		for (int i=0; i<n; i++) {
			map.put(sc.nextLine(),"");
		}
		
		// Close the Scanner to free up resources
		sc.close();

		// Print the size of the HashMap, which represents the number of unique entries
		System.out.println(map.size());
	}
}

