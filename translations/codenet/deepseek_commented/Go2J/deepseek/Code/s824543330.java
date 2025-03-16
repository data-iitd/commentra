public class Main {
    public static void main(String[] args) {
        // Declare two integer variables a and b
        int a, b;
        
        // Read two integers from the standard input and store them in a and b
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Check if the product of a and b is even or odd
        if (a * b % 2 == 0) {
            // If the product is even, print "Even"
            System.out.println("Even");
        } else {
            // If the product is odd, print "Odd"
            System.out.println("Odd");
        }
    }
}
