public class Main {
    public static void main(String[] args) {
        // Declare an integer variable 'x' to store the input value
        int x;
        // Create a Scanner object to read input from the standard input stream
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        // Read an integer value from the standard input and store it in 'x'
        x = scanner.nextInt();
        // Check if 'x' is greater than or equal to 1200
        if (x >= 1200) 
            // If the condition is true, print "ARC" to the standard output
            System.out.println("ARC");
        else 
            // Otherwise, print "ABC" to the standard output
            System.out.println("ABC");
    }
}
