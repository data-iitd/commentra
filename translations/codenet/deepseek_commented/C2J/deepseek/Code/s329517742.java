public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Step 4: Create a Scanner object to read input.
        int a = scanner.nextInt(); // Step 5: Read the first integer from the user input.
        int b = scanner.nextInt(); // Step 6: Read the second integer from the user input.
        if (500 * a >= b) { // Step 7: Check if the product of 500 and a is greater than or equal to b.
            System.out.println("Yes"); // Step 8: Print "Yes" if the condition is true.
        } else {
            System.out.println("No"); // Step 9: Print "No" if the condition is false.
        }
        scanner.close(); // Step 10: Close the scanner to free up resources.
    }
}
