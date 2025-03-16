import java.util.Scanner; // Importing the Scanner class for reading input from the console

public class Main {

	public static void main(String[] args) { // Main method to start the execution of the program
		Scanner scanner = new Scanner(System.in); // Creating a new Scanner object to read input from the console
		char[] s = scanner.next().toCharArray(),t = scanner.next().toCharArray(); // Reading two strings as character arrays from the console

		boolean check = false; // Initializing a boolean variable 'check' to false

		for(int i=s.length-t.length;i>=0;i--){ // Loop starts from the end of string 's' with length of 't'
			boolean check2 = true; // Initializing a boolean variable 'check2' to true

			for(int j=0;j<t.length;j++){ // Inner loop to compare each character of 't' with the corresponding character in 's'
				if(s[i+j] != '?' && s[i+j] != t[j]){ // If the characters don't match and '?' is not present
					check2 = false; // Setting 'check2' to false
				}
			}

			if(check2){ // If all characters match in the current position
				check = true; // Setting 'check' to true
				for(int j=0;j<t.length;j++){ // Copying the characters of 't' to the corresponding positions in 's'
					s[i+j] = t[j];
				}
			}

			if(check){ // If 'check' is true, break the outer loop
				break;
			}
		}

		if(check){ // If all the characters of 't' are found in 's', print the restored string 's'
			for(int i=0;i<s.length;i++){
				if(s[i] == '?'){ // If the character is '?'
					System.out.print("a"); // Print 'a' as the output
				}else{
					System.out.print(s[i]); // Print the character from 's'
				}
			}
			System.out.println(); // Print a newline after the string is printed
		}else{ // If 'check' is false, print "UNRESTORABLE"
			System.out.println("UNRESTORABLE");
		}
	}

}
