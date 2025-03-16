import java.util.Scanner;

public class GCD_LCM {
    
    // Function to find the greatest common divisor (GCD) of two numbers using Euclidean algorithm
    public static int G(int a, int b) {
        // Continue the loop until the remainder is zero
        while (a % b != 0) {
            // Swap a and b, and update a with the new value of b
            int temp = b;
            b = a % b;
            a = temp;
        }
        // Return the greatest common divisor (GCD)
        return b;
    }

    // Function to find the least common multiple (LCM) of two numbers
    public static int L(int a, int b) {
        // Find the GCD of a and b using the G function
        int gcd = G(a, b);
        // Return the product of a and b divided by their GCD
        return a * b / gcd;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input as a single line and split it by spaces
        String input = scanner.nextLine();
        String[] parts = input.split(" ");
        
        // Assign the input values to variables x, y, a, and b
        int x = Integer.parseInt(parts[0]);
        int y = Integer.parseInt(parts[1]);
        int a = Integer.parseInt(parts[2]);
        int b = Integer.parseInt(parts[3]);
        
        // Find the least common multiple (LCM) of x and y using the L function
        int lcm = L(x, y);
        
        // Calculate the result by subtracting (a-1) from b divided by lcm
        System.out.println(b / lcm - (a - 1) / lcm);
        
        scanner.close();
    }
}

// <END-OF-CODE>
