import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scan = new Scanner(System.in);
        
        // Read two integers from the user: n and k
        int n = scan.nextInt();
        int k = scan.nextInt();
        
        // Increment n by 1
        n++;
        
        // Initialize a variable z to store the adjustment needed to make n divisible by k
        int z = 0;
        
        // Check if n is not divisible by k
        if (n % k != 0) {
            // Calculate the adjustment needed to make n divisible by k
            z = k - n % k;
        }
        
        // Output the final result, which is n plus the adjustment z
        System.out.println(n + z);
    }
}
