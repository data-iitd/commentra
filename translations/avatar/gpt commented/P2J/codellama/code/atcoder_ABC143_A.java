// Read two integers A and B from user input, separated by a space
Scanner sc = new Scanner(System.in);
int A = sc.nextInt();
int B = sc.nextInt();

// Calculate the result by subtracting twice the value of B from A
int ans = A - 2 * B;

// If the result is negative, set it to zero
if (ans < 0) {
    ans = 0;
}

// Print the final result
System.out.println(ans);

