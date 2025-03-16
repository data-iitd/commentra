import java.util.*; // Importing the Scanner class from the utility package

class Main {
    // Declaring a final Scanner object named 'sc' for reading input
    final Scanner sc = new Scanner(System.in);

    // Declaring a final constant named 'DEVISOR' with a value of 1000000007+7
    final long DEVISOR = 1000000000+7;

    public static void main(String[] args) {
        // Creating an instance of the Main class and calling its run() method
        new Main().run();
    }

    private void run() {
        // Reading the long input values 'n' and 'k' from the user
        long n = sc.nextLong();
        long k = sc.nextLong();

        // Initializing the answer variable 'ans' to zero
        long ans = 0;

        // Using a for loop to iterate from 'k' to 'n+1' (inclusive)
        for (long i = k; i <= n+1; i++) {
            // Calculating the maximum number of pairs that can be formed using 'i' stars
            long max = i * (2 * n - i + 1) / 2;

            // Calculating the minimum number of pairs that can be formed using 'i-1' stars
            long min = i * (i - 1) / 2;

            // Adding the number of pairs formed between 'min' and 'max' (exclusive) to the answer
            ans += (max - min + 1);
        }

        // Printing the answer modulo 'DEVISOR'
        System.out.println(ans % DEVISOR);
    }
}
