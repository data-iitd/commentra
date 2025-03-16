

Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input from the user.
int n = scanner.nextInt();  // Read an integer input from the user and store it in the variable `n`.
for (int i = n; i > 0; i--) {  // Iterate from `n` down to 1, decrementing by 1 in each iteration.
    if (n % i == 0) {  // Check if `n` is divisible by `i`.
        n = i;  // Update `n` to `i` if `n` is divisible by `i`.
        System.out.print(i + " ");  // Print the value of `i` followed by a space.
    }
}

// END-OF-CODE