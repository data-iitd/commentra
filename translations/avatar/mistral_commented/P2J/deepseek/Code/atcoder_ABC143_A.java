import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from the user, separated by a space
        String[] input = scanner.nextLine().split(" ");
        int A = Integer.parseInt(input[0]);
        int B = Integer.parseInt(input[1]);
        
        // Calculate the difference between A and 2 times B
        int ans = A - 2 * B;
        
        // Check if the difference is negative
        if (ans < 0) {
            // If it is, set it to zero
            ans = 0;
        }
        
        // Print the final answer
        System.out.println(ans);
    }
}

