public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;
        
        // Create a Scanner object to read input from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Read two integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        
        // Calculate the product of the two integers and check if it is even or odd
        int product = a * b;
        if (product % 2 == 0) {
            // If the product is even, print "Even"
            System.out.println("Even");
        } else {
            // If the product is odd, print "Odd"
            System.out.println("Odd");
        }
    }
}
