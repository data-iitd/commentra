public class Main {
    public static void main(String[] args) {
        // Include the necessary header files for input and output operations
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        
        // Declare integer variables to store input values
        int h = scanner.nextInt();
        int w = scanner.nextInt();
        int hh = scanner.nextInt();
        int ww = scanner.nextInt();
        
        // Read values from the standard input and store them in the variables
        System.out.println((h - hh) * (w - ww));
        
        // Perform arithmetic operation to calculate the area of a rectangle
        // Output the result to the standard output
    }
}
