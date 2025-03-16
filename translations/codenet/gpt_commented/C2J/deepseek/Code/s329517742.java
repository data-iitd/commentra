public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read two integers from the user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Check if 500 times the value of 'a' is greater than or equal to 'b'
        if (500 * a >= b) 
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        else 
            // If the condition is false, print "No"
            System.out.println("No");

        // Return 0 to indicate successful execution of the program
