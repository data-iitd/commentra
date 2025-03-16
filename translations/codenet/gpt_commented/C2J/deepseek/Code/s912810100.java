public class Main {
    public static void main(String[] args) {
        // Declare variables to hold two integers and the results
        int a, b, x, y;

        // Create a Scanner object to read user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the product of a and b
        x = a * b;

        // Calculate the perimeter of a rectangle with sides a and b
        y = (a + b) * 2;

        // Print the results: product and perimeter
        System.out.println(x + " " + y);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}
