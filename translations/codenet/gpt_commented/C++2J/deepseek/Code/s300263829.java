public class Main {
    public static void main(String[] args) {
        int a, b; // Declare two integer variables a and b to store user input
        
        // Prompt the user to enter two integers
        System.out.print("Enter two integers: "); 
        java.util.Scanner scanner = new java.util.Scanner(System.in); // Create a Scanner object to read input
        a = scanner.nextInt(); // Read the first integer from user input and store it in variable a
        b = scanner.nextInt(); // Read the second integer from user input and store it in variable b
        
        // Calculate the product of a and b and display the result
        System.out.println("The product is: " + a * b); 
    }
}
