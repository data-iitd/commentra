public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;
        x = 0; y = 0;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from the user using the Scanner object and store them in variables x and y respectively
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Print the product of x and y and the sum of 2 times x and 2 times y using System.out.println
        System.out.println(x * y + " " + (2 * x + 2 * y));
    }
}
