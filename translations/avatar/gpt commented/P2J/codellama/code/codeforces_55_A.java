// Read an integer input from the user
Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();

// Continuously divide n by 2 while it is even
while (n % 2 == 0) {
    n /= 2;
}

// Check if the resulting value of n is 1
if (n == 1) {
    // If n is 1, it means the original number was a power of 2
    System.out.println("YES");
} else {
    // If n is not 1, the original number was not a power of 2
    System.out.println("NO");
}

