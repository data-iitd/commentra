public class Main {
    public static void main(String[] args) {
        int a, b; // Declare two integer variables 'a' and 'b'
        // Initialize them to zero by default

        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a new Scanner object to read input from the standard input

        a = scanner.nextInt(); // Read an integer value from the standard input and store it in variable 'a'
        b = scanner.nextInt(); // Read an integer value from the standard input and store it in variable 'b'

        if((a*b)%2 == 0){ // Check if the product of 'a' and 'b' is even
            System.out.println("Even"); // If it is even, print "Even" to the standard output
        }else{
            System.out.println("Odd"); // If it is odd, print "Odd" to the standard output
        }
    }
}
