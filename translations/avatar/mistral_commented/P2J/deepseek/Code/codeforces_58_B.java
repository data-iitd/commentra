public class Main {
    public static void main(String[] args) {
        // Ask the user to input an integer value
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize a variable i and set its value to n
        for (int i = n; i > 0; i--) {
            // Check if n is divisible by the current value of i
            if (n % i == 0) {
                // If the condition is true, update the value of n to i
                n = i;
                // Print the current value of i
                System.out.print(i + " ");
            }
        }
        System.out.println(); // Print a newline at the end
    }
}
