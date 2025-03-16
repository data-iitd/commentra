public class DivisibleByFour {
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;

        // Read three integers from the user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the number formed by a, b, and c is divisible by 4
        // The number is formed as 100*a + 10*b + c
        if ((100 * a + 10 * b + c) % 4 == 0) {
            // If the number is divisible by 4, output "YES"
            System.out.println("YES");
        } else {
            // If the number is not divisible by 4, output "NO"
            System.out.println("NO");
        }
    }
}
