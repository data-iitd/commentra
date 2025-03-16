// Function to find the number of digits in a given number
public static void main(String[] args) {
    // Read the number of test cases from the standard input
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();

    // Initialize variables
    int i = 1;
    int ans = 0;

    // Calculate the answer using a while loop
    while (10 ** i <= N) {
        // Add the difference between the current power of 10 and the previous power of 10 to the answer
        ans += (10 ** i - 10 ** (i - 1));
        // Increment the index i by 2
        i += 2;
    }

    // Add the remaining digits of the number N to the answer
    ans += Math.max(0, N - 10 ** (i - 1) + 1);

    // Print the answer
    System.out.println(ans);
}

// End of code
