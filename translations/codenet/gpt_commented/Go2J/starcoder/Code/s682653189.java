public class Main {

	public static void main(String[] args) {
		// Declare a variable to hold the input string
		String s;
		
		// Read a string input from the user
		Scanner sc = new Scanner(System.in);
		s = sc.next();
		
		// Loop through each character in the string
		for (int i = 0; i < s.length(); i++) {
			// Print 'x' for each character in the input string
			System.out.print("x");
		}
		
		// Print a newline after printing all 'x's
		System.out.println("");
	}
}
