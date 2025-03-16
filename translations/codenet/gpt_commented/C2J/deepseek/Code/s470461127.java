public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;
        
        // Initialize x and y to 0
        x = 0; 
        y = 0;   

        // Read two integer values from the user and store them in x and y
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextInt();
        y = scanner.nextInt();
        
        // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
        // Print the product and the perimeter
        System.out.println(x * y + " " + (2*x) + (2*y));  

        // Return 0 to indicate successful completion of the program
    }
}
