
// Import necessary libraries for mathematical operations, data structures, and system functions
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read four integers from input
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        
        // Calculate the maximum value from the products of the pairs and return it
        System.out.println(Math.max(a * c, b * d, a * d, b * c));
    }
}

