
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read three integers from the user
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        
        // Close the Scanner object to free up resources
        sc.close();
        
        // Print the values of z, x, and y in the reverse order
        System.out.println(z + " " + x + " " + y);
    }
}

