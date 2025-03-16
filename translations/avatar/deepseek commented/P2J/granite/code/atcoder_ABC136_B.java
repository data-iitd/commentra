
import java.util.Scanner;  // Import the Scanner class from the java.util package

public class atcoder_ABC136_B{  // Define the atcoder_ABC136_B class
    public static void main(String[] args) {  // Define the main method to execute the program logic
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read input from the user
        int N = scanner.nextInt();  // Read an integer input from the user and assign it to N
        int i = 1;  // Initialize the variable i to 1
        int ans = 0;  // Initialize the variable ans to 0
        while (Math.pow(10, i) <= N) {  // Start a while loop that continues as long as 10^i is less than or equal to N
            ans += (int) Math.pow(10, i) - (int) Math.pow(10, i - 1);  // Add the difference between 10^i and 10^(i-1) to ans
            i += 2;  // Increment i by 2 for the next iteration
        }
        ans += Math.max(0, N - (int) Math.pow(10, i - 1) + 1);  // Add the maximum of 0 and N - 10^(i-1) + 1 to ans
        System.out.println(ans);  // Print the final value of ans
    }
}

Translate the above Java code to C++ and end with comment "