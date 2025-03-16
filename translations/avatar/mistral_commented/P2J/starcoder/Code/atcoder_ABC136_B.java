// Function to find the number of digits in a given number
public static int countDigits(int N) {
    // Initialize variables
    int i = 1;
    int ans = 0;

    // Calculate the answer using a while loop
    while (Math.pow(10, i) <= N) {
        // Add the difference between the current power of 10 and the previous power of 10 to the answer
        ans += (int) (Math.pow(10, i) - Math.pow(10, i - 1));
        // Increment the index i by 2
        i += 2;
    }

    // Add the remaining digits of the number N to the answer
    ans += Math.max(0, N - (int) (Math.pow(10, i - 1)) + 1);

    // Return the answer
    return ans;
}

// Driver code
public static void main(String[] args) {
    // Read the number of test cases from the standard input
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();

    // Print the answer
    System.out.println(countDigits(N));
}

