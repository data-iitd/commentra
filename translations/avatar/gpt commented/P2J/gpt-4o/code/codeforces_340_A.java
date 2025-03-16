import java.util.Scanner;

public class GCDLCM {
    
    // Function to compute the Greatest Common Divisor (GCD) of two numbers
    public static int G(int a, int b) {
        // Continue looping until b becomes 0
        while (b != 0) {
            // Update a and b using the Euclidean algorithm
            int temp = b;
            b = a % b;
            a = temp;
        }
        // Return the GCD
        return a;
    }

    // Function to compute the Least Common Multiple (LCM) of two numbers
    public static int L(int a, int b) {
        // Calculate LCM using the relationship between GCD and LCM
        return a * (b / G(a, b));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values
        String[] input = scanner.nextLine().split(" ");
        
        // Convert the input strings to integers
        int x = Integer.parseInt(input[0]);
        int y = Integer.parseInt(input[1]);
        int a = Integer.parseInt(input[2]);
        int b = Integer.parseInt(input[3]);
        
        // Calculate the LCM of x and y
        int lcm = L(x, y);
        
        // Calculate and print the count of multiples of LCM in the range [a, b]
        System.out.println(b / lcm - (a - 1) / lcm);
        
        scanner.close();
    }
}

// <END-OF-CODE>
