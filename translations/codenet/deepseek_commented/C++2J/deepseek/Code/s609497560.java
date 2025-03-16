public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input
        int a = scanner.nextInt(); // Read an integer from the user
        System.out.println(a + (a * a) + (a * a * a)); // Calculate and print the sum of 'a', 'a^2', and 'a^3'
    }
}
