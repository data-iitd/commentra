public class Main {
    public static void main(String[] args) {
        // Declare two integer variables, A and B, and read their values from the standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();

        // Declare an integer variable, ans, to store the result of our calculation
        int ans;

        // Use an if statement to check the value of A
        if (A >= 6 && A <= 12) {
            // If A is between 6 and 12 (inclusive), calculate the answer as the integer division of B by 2
            ans = B / 2;
        } else if (A > 12) {
            // If A is greater than 12, assign the value of B directly to the ans variable
            ans = B;
        } else {
            // If A is less than 6, set ans to 0 (or any other appropriate value)
            ans = 0;
        }

        // Print the value of ans
        System.out.println(ans);

        // End of code
    }
}
