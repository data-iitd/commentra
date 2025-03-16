public class Main {
    public static void main(String[] args) {
        // Declare variables A, B, and C of type int
        int A, B, C;

        // Read three integers from the standard input using Scanner class
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();

        // Check if the condition C-A+B is less than zero
        if (C - A + B < 0) {
            // If the condition is true, print zero as output
            System.out.println("0");
        } else {
            // If the condition is false, calculate the value of C-A+B and print it as output
            System.out.println(C - A + B);
        }
    }
}
