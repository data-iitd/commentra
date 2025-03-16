import java.util.Scanner;

public class ShoeCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from input: h (height) and a (height per shoe)
        int h = scanner.nextInt();
        int a = scanner.nextInt();
        
        // Calculate the number of shoes needed by performing integer division
        int sho = h / a;
        
        // Calculate the remaining height after accounting for full shoes
        int am = h % a;
        
        // If there is any remaining height, we need one additional shoe
        if (am != 0) {
            sho += 1;  // Increment the shoe count by 1 for the remaining height
        }
        
        // Print the total number of shoes required
        System.out.println(sho);
        
        scanner.close();
    }
}

// <END-OF-CODE>
