
// The main function is the entry point of the program
public static void main(String[] args) {
	// Declare variables n, k, and cnt of type int
	int n, k, cnt;

	// Read two integers n and k from the standard input using Scanner
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	k = sc.nextInt();
	// Initialize variable cnt to zero
	cnt = 0;
	// Loop through n times using a while loop
	while (n-- > 0) {
		// Declare variable h of type int
		int h;

		// Read an integer h from the standard input using Scanner
		h = sc.nextInt();
		// If h is greater than or equal to k, increment cnt by 1
		if (h >= k)
			cnt++;
	}
	// Print the value of cnt to the standard output using System.out.println()
	System.out.println(cnt);
	// Return 0 to indicate successful execution of the program
	return 0;
}

