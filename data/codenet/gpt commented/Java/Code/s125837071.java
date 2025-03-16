import java.util.Scanner;

public class Main {

    @SuppressWarnings("resource")
    public static void main(String args[]) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read an integer input 'n' from the user
        int n = scanner.nextInt();
        
        // Initialize the answer variable to 1
        long ans = 1;
        
        // Define the modulus value to prevent overflow
        int mod = (int) Math.pow(10, 9) + 7;
        
        // Loop through all integers from 2 to n
        for (int i = 2; i <= n; i++) {
            // Check if 'i' is a prime number by ensuring it is not divisible by any number less than itself
            for (int j = 2; (i % j != 0 && j < i) || j == i; j++) {
                // If 'j' equals 'i', it means 'i' is a prime number
                if (j == i) {
                    // Initialize a variable to accumulate the sum
                    int s = 0;
                    
                    // Calculate the sum of the function findS for all integers from 1 to n
                    for (int k = 1; k <= n; k++) {
                        s += findS(k, i);
                    }

                    // Update the answer by multiplying with (s + 1) and taking modulo
                    ans = (ans * (s + 1)) % mod;
                }
            }
        }
        
        // Print the final answer
        System.out.println(ans);
    }

    // Function to find the number of times 'k' can be divided by 'i'
    private static int findS(int k, int i) {
        int s = 0;
        
        // Count how many times 'k' can be divided by 'i'
        for (int j = k; j % i == 0; j /= i) {
            s++;
        }
        
        // Return the count
        return s;
    }
}
