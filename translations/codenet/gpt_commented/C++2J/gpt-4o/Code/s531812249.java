import java.util.Scanner;

public class Main {
    // Define a constant for the value of PI
    static final double PI = 3.14159265358979;

    public static void main(String[] args) {
        // Declare variables to hold the number of groups
        int n, m;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Input the number of groups n and m
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Initialize the answer variable to store the total pairs
        int ans = 0;

        // Calculate the number of pairs within group n
        // The formula n*(n-1)/2 gives the number of ways to choose 2 from n
        ans += n * (n - 1) / 2;

        // Calculate the number of pairs within group m
        // Similarly, m*(m-1)/2 gives the number of ways to choose 2 from m
        ans += m * (m - 1) / 2;

        // Output the total number of pairs
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
