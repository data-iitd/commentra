// The main function is the entry point of the program.
public static void main(String[] args) {
	// Initialize a Scanner object named sc.
	Scanner sc = new Scanner(System.in);

	// Read two integers A and B from the standard input.
	int A = sc.nextInt();
	int B = sc.nextInt();

	// Calculate the maximum value of A+B, A-B, and A*B using the max function.
	int mx = max(A+B, A-B);
	mx = max(mx, A*B);

	// Print the maximum value.
	System.out.println(mx);
}

