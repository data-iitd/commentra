
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		// Create a Scanner object to read input from the standard input stream (keyboard)
		Scanner sc = new Scanner(System.in);
		
		// Read a line of input from the user and store it in the variable S
		String S = sc.nextLine();
		
		// Close the Scanner object to free up resources
		sc.close();

		// Check if the length of S is odd or even
		if(S.length() % 2 == 1){
			// If the length of S is odd, remove the last character from S
			S = S.substring(0, S.length() - 1);
		}
		else{
			// If the length of S is even, remove the last two characters from S
			S = S.substring(0, S.length() - 2);
		}

		// Continue looping as long as the length of S is greater than 0
		for(; S.length() > 0; S = S.substring(0, S.length() - 2)){
			// Check if S is an even string using the isEvenString method
			if(isEvenString(S)){
				// If S is an even string, break the loop
				break;
			}
		}
		
		// Print the length of S
		System.out.println(S.length());
	}

	// Method to check if a given string s is an even string
	static boolean isEvenString(String s){
		// Divide the string s into two equal parts and compare them
		String a = s.substring(0, s.length()/2);
		String b = s.substring(s.length()/2);
		if(a.equals(b)){
			// If the two parts are equal, return true
			return true;
		}
		else{
			// If the two parts are not equal, return false
			return false;
		}
	}

}

