public class Main {
    public static void main(String[] args) {
        int a; // Declare an integer variable named 'a'

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input
        a = scanner.nextInt(); // Read an integer value from the user and store it in variable 'a'

        // Calculate the value of the expression (a + (a * a) + (a * a * a)) and store it in the output buffer
        System.out.println(a + (a * a) + (a * a * a));
    }
}
