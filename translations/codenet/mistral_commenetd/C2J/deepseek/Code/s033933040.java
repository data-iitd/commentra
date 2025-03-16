public class Main {
    public static void main(String[] args) {
        // Declare variables
        int a, b, mawari, menseki; // Declare variables a, b, mawari, and menseki as integers

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read input values for variables a and b from the user
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Assign the variable mawari the sum of the squares of a and b
        mawari = a * a + b * b;
        // Assign the variable menseki the product of a and b
        menseki = a * b;

        // Print the values of menseki and mawari to the console
        System.out.println(menseki + " " + mawari);
    }
}
