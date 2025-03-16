public class Main {
    public static void main(String[] args) {
        // Declare integer variables to store user input and the result
        int a, b;
        int ans;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from the user
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Initialize the result variable to 0
        ans = 0;

        // Check the value of 'a' and update 'ans' accordingly
        if (a >= 13) {
            // If 'a' is 13 or greater, set 'ans' to 'b'
            ans = b;
        } else if (a >= 6) {
            // If 'a' is between 6 and 12 (inclusive), set 'ans' to half of 'b'
            ans = b / 2;
        }

        // Print the result
        System.out.println(ans);
    }
}
