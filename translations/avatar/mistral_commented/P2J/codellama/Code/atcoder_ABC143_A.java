// Read two integers from the user, separated by a space
Scanner sc = new Scanner(System.in);
int A = sc.nextInt();
int B = sc.nextInt();

// Calculate the difference between A and 2 times B
int ans = A - 2 * B;

// Check if the difference is negative
if (ans < 0) {
    // If it is, set it to zero
    ans = 0;
}

// Print the final answer
System.out.println(ans);

