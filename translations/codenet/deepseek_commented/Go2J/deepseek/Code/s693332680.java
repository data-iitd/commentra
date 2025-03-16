public class Main {
    public static void main(String[] args) {
        // Declare three integer variables x, a, and b to store input values.
        int x, a, b;
        
        // Read three integers from the standard input and assign them to x, a, and b.
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
        if (b - a <= 0) {
            System.out.println("delicious");
        } else if (b - a <= x) {
            System.out.println("safe");
        } else {
            System.out.println("dangerous");
        }
    }
}
