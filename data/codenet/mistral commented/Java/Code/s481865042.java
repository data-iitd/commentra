import java.util.Scanner; // Importing the Scanner class for reading input from the console

public class Main {
	public static void main(String[] args){ // Main method to start the execution of the program
		Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read input from the console
		String s = sc.next(); // Reading the first input as a string
		long k = sc.nextLong(); // Reading the second input as a long integer

		// Initializing a StringBuffer object named sb to store the transformed string
		StringBuffer sb=new StringBuffer();

		for(int i = 0; i<s.length(); i++){ // Loop to iterate through each character in the string s
			if((26-(s.charAt(i)-'a'))<=k && s.charAt(i)!='a'){ // Checking condition to transform certain characters based on the given long integer k
				k-=26-(s.charAt(i)-'a'); // Decrementing the value of k based on the transformed character
				sb.append('a'); // Appending 'a' to the StringBuffer sb
			}else{
				sb.append(s.charAt(i)); // Appending the original character to the StringBuffer sb if the condition is not met
			}
		}

		// Checking condition if there is still a remaining value of k after the transformation of all characters
		if(k>0){
			char t=sb.charAt(s.length()-1); // Storing the last character of the transformed string in a character variable t
			sb.delete(s.length()-1,s.length()); // Deleting the last character from the StringBuffer sb
			sb.append((char)('a'+(t-'a'+k)%26)); // Appending the transformed character based on the remaining value of k
		}

		// Printing the transformed string stored in the StringBuffer sb to the console
		System.out.println(sb);
	}
}
