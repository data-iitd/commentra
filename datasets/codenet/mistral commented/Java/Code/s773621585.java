
import java.util.HashMap; // Importing HashMap class from java.util package
import java.util.Scanner; // Importing Scanner class from java.util package

public class Main {
	public static void main(String[] args) {
		// Creating an empty HashMap with String as key and String as value
		HashMap<String, String> map = new HashMap<String, String>();

		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console

		// Reading the number of lines to be read from the console
		int n = sc.nextInt();
		System.out.println("Enter the number of strings to be stored in the HashMap: " + n);

		// Reading the strings to be stored in the HashMap
		String str= sc.nextLine();
		System.out.println("Enter the string to be associated with each key: ");
		for (int i=0; i<n; i++) {
			// Reading a line from the console and storing it as key in the HashMap with an empty value
			map.put(sc.nextLine(),"");
			System.out.println("Stored key: " + sc.nextLine());
		}
		sc.close(); // Closing the Scanner object after reading all the required inputs

		// Printing the size of the HashMap
		System.out.println("Size of the HashMap: " + map.size());
	}
}