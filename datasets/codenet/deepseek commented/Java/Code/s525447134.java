

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Create a Scanner object to read input from the standard input stream (keyboard)
		Scanner sc = new Scanner(System.in);
		
		// Read a string input from the user
		String s = sc.next();
		
		// Check if the input string is "Sunny". If it is, print "Cloudy".
		if(s.equals("Sunny")) {
			System.out.println("Cloudy");
		} 
		// If the input string is not "Sunny", check if it is "Cloudy". If it is, print "Rainy".
		else if(s.equals("Cloudy")) {
			System.out.println("Rainy");
		} 
		// If the input string is neither "Sunny" nor "Cloudy", print "Sunny".
		else {
			System.out.println("Sunny");
		}
	}

}

