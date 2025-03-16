public class Main {
    public static void main(String[] args) {
        int a, b; // Declare two integer variables to store input values

        // Read two integer values from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and output the result of the expression (6 - a - b)
        // This assumes that a and b are part of a game or problem where their sum should not exceed 6
        System.out.println(6 - a - b);
    }
}
