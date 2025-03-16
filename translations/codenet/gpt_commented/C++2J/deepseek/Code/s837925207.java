public class Main {
    public static void main(String[] args) {
        int x, ans = 0; // Declare variables x for input and ans for the result

        // Read an integer input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextInt();

        // Calculate the result as the sum of x, x squared, and x cubed
        ans = x + x*x + x*x*x;

        // Output the calculated result to the console
        System.out.println(ans);
    }
}
