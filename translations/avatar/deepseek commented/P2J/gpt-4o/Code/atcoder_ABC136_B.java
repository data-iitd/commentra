import java.util.Scanner;

public class Main {
    public static void main(String[] args) {  // The main method to execute the program logic
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input
        int N = scanner.nextInt();  // Read an integer input from the user and assign it to N
        int i = 1;  // Initialize the variable i to 1
        long ans = 0;  // Initialize the variable ans to 0

        while (Math.pow(10, i) <= N) {  // Start a while loop that continues as long as 10^i is less than or equal to N
            ans += (Math.pow(10, i) - Math.pow(10, i - 1));  // Add the difference between 10^i and 10^(i-1) to ans
            i += 2;  // Increment i by 2 for the next iteration
        }
        
        ans += Math.max(0, N - Math.pow(10, i - 1) + 1);  // Add the maximum of 0 and N - 10^(i-1) + 1 to ans
        System.out.println(ans);  // Print the final value of ans

        scanner.close();  // Close the scanner
    }
}

// <END-OF-CODE>
