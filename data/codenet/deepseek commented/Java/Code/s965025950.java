
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user input
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        
        // Print the values of z, x, and y in the order z, x, y
        System.out.println(z + " " + x + " " + y);
        
        // Close the Scanner object to free up resources
        sc.close();
    }
}

