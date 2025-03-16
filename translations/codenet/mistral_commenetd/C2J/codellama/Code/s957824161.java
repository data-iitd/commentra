
public class Main {
    public static void main(String[] args) {
        // The main function is the entry point of the program

        System.out.print("Enter two integers: "); // Print a message asking for two integers

        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read from the standard input

        int x = scanner.nextInt(); // Read an integer from the standard input and store it in variable x
        int y = scanner.nextInt(); // Read an integer from the standard input and store it in variable y

        // Perform some arithmetic operations

        int result1 = x * y; // Multiply x and y and store the result in result1
        int result2 = 2 * x + 2 * y; // Multiply x by 2 and y by 2, then add the results

        // Print the results

        System.out.printf("The product of %d and %d is: %d\n", x, y, result1); // Print the message and the product of x and y
        System.out.printf("The sum of 2 times %d and 2 times %d is: %d\n", x, y, result2); // Print the message and the sum of 2 times x and 2 times y

        scanner.close(); // Close the Scanner object
    }
}

