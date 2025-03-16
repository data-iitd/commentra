import java.util.*; // Importing Scanner class for input operations

class Main {
	public static void main(String[] args) { // Main method, entry point of the program
		Scanner sc = new Scanner(System.in); // Creating a Scanner object to read input
		int N = sc.nextInt(); // Reading an integer input, N represents the number of positions to shift
		char c[] = sc.next().toCharArray(); // Reading a string input and converting it to a character array
		for (int i=0; i<c.length; i++) { // Looping through each character in the array
			c[i] = (char)((c[i]-'A'+N) % 26 + 'A'); // Shifting each character by N positions
		}
		System.out.println(c); // Printing the shifted character array
	}
}
