public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold user input
        int x, y;

        // Create a Scanner object to read input from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from standard input
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Calculate the sum of x and half of y, then print the result
        System.out.println(x + y / 2);
    }
}
