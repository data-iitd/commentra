import java.util.Scanner;

public class CookieCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read a line of input, split it into parts, and convert each part to an integer
        String[] input = scanner.nextLine().split(" ");
        int[] cookies = new int[input.length];
        for (int i = 0; i < input.length; i++) {
            cookies[i] = Integer.parseInt(input[i]);
        }

        // Calculate the leftover cookies after taking some from the third type
        int leftOver = cookies[0] - cookies[2];

        // Determine the number of cookies Takahashi can take, ensuring it's not negative
        int takahashi = Math.max(0, leftOver);

        // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
        // If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
        if (takahashi > 0) {
            System.out.println(takahashi + " " + cookies[1]);
        } else {
            System.out.println(takahashi + " " + Math.max(0, cookies[1] - Math.abs(leftOver)));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
