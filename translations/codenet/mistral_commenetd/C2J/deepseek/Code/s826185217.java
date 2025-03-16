public class Main {
    public static void main(String[] args) {
        int a, b, c, d; // Declare four integer variables

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a new Scanner object to read input from the standard input
        a = scanner.nextInt(); // Read an integer from the standard input and store it in the variable a
        b = scanner.nextInt(); // Read an integer from the standard input and store it in the variable b
        c = scanner.nextInt(); // Read an integer from the standard input and store it in the variable c
        d = scanner.nextInt(); // Read an integer from the standard input and store it in the variable d

        if (a + b > c + d) { // Check if the sum of a and b is greater than the sum of c and d
            System.out.println("Left"); // If true, print "Left" to the standard output
        } else if (a + b < c + d) { // Check if the sum of a and b is less than the sum of c and d
            System.out.println("Right"); // If true, print "Right" to the standard output
        } else { // If neither of the above conditions is true
            System.out.println("Balanced"); // Print "Balanced" to the standard output
        }
    }
}
