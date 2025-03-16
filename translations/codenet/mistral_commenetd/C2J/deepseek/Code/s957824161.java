public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Print a message asking for two integers
        System.out.print("Enter two integers: ");

        // Read two integers from the standard input and store them in variables x and y
        x = scanner.nextInt();
        y = scanner.nextInt();

        // Perform some arithmetic operations

        // Multiply x and y and store the result in result1
        int result1 = x * y;

        // Multiply x by 2 and y by 2, then add the results
        int result2 = 2 * x + 2 * y;

        // Print the results

        // Print the message and the product of x and y
        System.out.printf("The product of %d and %d is: %d\n", x, y, result1);

        // Print the message and the sum of 2 times x and 2 times y
        System.out.printf("The sum of 2 times %d and 2 times %d is: %d\n", x, y, result2);
    }
}
