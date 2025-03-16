// Main function where the program execution begins
public static void main(String[] args) {
	// Declare variables to store integers and a character
	int a, b;
	char S;
	
	// Infinite loop to continuously take input and perform operations
	while (true) {
		// Take input in the format a S b
		Scanner sc = new Scanner(System.in);
		a = sc.nextInt();
		S = sc.next().charAt(0);
		b = sc.nextInt();
		
		// Perform operations based on the value of S
		if (S == '+') System.out.println(a + b);
		if (S == '-') System.out.println(a - b);
		if (S == '*') System.out.println(a * b);
		if (S == '/') System.out.println(a / b);
		
		// Break the loop if S is '?'
		if (S == '?') break;
	}
}
