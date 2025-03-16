public class Main {
    public static void main(String[] args) {
        // Declare variables to hold two integers and the result
        int a, b, s;

        // Create a Scanner object to read user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the result using the formula: (a*b) - (a + b) + 1
        s = (a * b) - (a + b) + 1;

        // Output the result to the console
        System.out.println(s);
    }
}
