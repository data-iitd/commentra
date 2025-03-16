public class Main {
    public static void main(String[] args) {
        // Declare integer variables to hold input values and results
        int a, b, c, d, i, j;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read four integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Calculate the product of the first two integers
        i = a * b;

        // Calculate the product of the last two integers
        j = c * d;

        // Compare the two products and print the larger one
        if (i > j) {
            // If the first product is greater, print it
            System.out.println(i);
        } else {
            // Otherwise, print the second product
            System.out.println(j);
        }

        // Return 0 to indicate successful completion of the program
        scanner.close();
    }
}
