import java.util.Scanner;

public class PrimeNumbers {
    // Declare a flag array to keep track of prime numbers
    static boolean[] flag;

    // Function to find prime numbers up to a given limit
    static void prime(int num) {
        int i, j;

        // Allocate memory for flag array of size num+1
        flag = new boolean[num + 1];

        // Loop through numbers from 2 to num
        for (i = 2; i * i <= num; i++) {
            // If a number is not marked as composite, mark all its multiples as composite
            if (!flag[i]) {
                for (j = 2; i * j <= num; j++) {
                    flag[i * j] = true;
                }
            }
        }
    }

    public static void main(String[] args) {
        int n, i, cnt;
        Scanner scanner = new Scanner(System.in);

        // Call prime function to find prime numbers up to 50000
        prime(50000);

        // Loop until user inputs 0
        while (true) {
            // Read user input for number n
            n = scanner.nextInt();
            // Break the loop if user inputs 0
            if (n == 0) {
                break;
            }
            // Initialize i and cnt to 0
            i = 2;
            cnt = 0;
            // Loop through numbers from 2 to square root of n
            while (i * i <= n) {
                // If i and n-i are both prime, increment cnt
                if (!flag[i] && !flag[n - i]) {
                    cnt++;
                }
                // Increment i for next iteration
                i++;
            }
            // Print the result
            System.out.println(cnt);
        }

        // Close the scanner
        scanner.close();
    }
}
