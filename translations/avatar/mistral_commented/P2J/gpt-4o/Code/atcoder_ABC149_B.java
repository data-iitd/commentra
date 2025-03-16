import java.util.Scanner;

public class CookieDistribution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Define an array 'cookies' by reading input
        int[] cookies = new int[3];
        for (int i = 0; i < 3; i++) {
            cookies[i] = scanner.nextInt();
        }
        
        // Calculate the difference between the number of cookies given to the first and second child
        int leftOver = cookies[0] - cookies[2];
        
        // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
        int takahashi = Math.max(0, leftOver);
        
        // Print the result using string concatenation
        System.out.println(takahashi + " " + 
            (takahashi > 0 ? cookies[1] : Math.max(0, cookies[1] - Math.abs(leftOver))));
        
        scanner.close();
    }
}

// <END-OF-CODE>
