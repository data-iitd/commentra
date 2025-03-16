import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from stdin
        Scanner sc = new Scanner(System.in);
        
        // Read two integers from user input
        int x = sc.nextInt();
        int y = sc.nextInt();
        
        // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
        // Print the results: product and perimeter
        System.out.println(x * y + " " + (2 * x + 2 * y));
        
        // Close the Scanner object
        sc.close();
    }
}
