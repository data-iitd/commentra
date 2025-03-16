
import java.util.Scanner;

public class codeforces_146_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String number = scanner.next();
        int h1 = 0;  // Sum of the first half
        int h2 = 0;  // Sum of the second half
        int x = 0;   // Flag to check if any number is not 4 or 7

        for (int i = 0; i < n; i++) {
            char c = number.charAt(i);
            if (c!= '4' && c!= '7') {
                System.out.println("NO");  // Print "NO" if an invalid number is found
                x += 1;                     // Increment the flag to indicate an invalid number was found
                break;                      // Exit the loop since we found an invalid number
            }

            if (i < n / 2) {
                h1 += c - '0';
            } else {
                h2 += c - '0';
            }
        }

        if (x == 0) {  // Proceed only if no invalid numbers were found
            if (h1 == h2) {
                System.out.println("YES");  // Print "YES" if the sums are equal
            } else {
                System.out.println("NO");   // Print "NO" if the sums are not equal
            }
        }
    }
}
