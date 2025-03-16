import java.util.Scanner; // Importing Scanner class for reading user input

public class Main {

	public static void main(String[] args) { // Main method to start the program

		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input
		String S = sc.nextLine(); // Reading a line of text as a String from the user input
		sc.close(); // Closing the Scanner object to free system resources

		// Checking if the length of the String S is odd or even
		if(S.length() % 2 == 1){
			S = S.substring(0, S.length() - 1); // Removing the last character if the length is odd
		}
		else{
			S = S.substring(0, S.length() - 2); // Removing the last two characters if the length is even
		}

		// Iterating through the String S to find the shortest even-length substring
		for(; S.length() > 0; S = S.substring(0, S.length() - 2)){
			if(isEvenString(S)){ // Checking if the current substring is even-length and equals to its reverse
				break; // Exiting the loop if an even-length substring is found
			}
		}
		// Printing the length of the even-length substring
		System.out.println(S.length());
	}

	// Helper method to check if a given String is even-length and equals to its reverse
	static boolean isEvenString(String s){
		String a = s.substring(0, s.length()/2); // Splitting the String into two halves
		String b = s.substring(s.length()/2);
		// Comparing the first half and the second half of the String for equality
		if(a.equals(b)){
			return true;
		}
		else{
			return false;
		}
	}

}
