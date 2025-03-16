
import java.util.Scanner;

public class codeforces_146_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Step 1: Take an integer input `n`
        String number = scanner.next();  // Step 1: Take a string of digits `number`

        int h1 = 0;  // Step 2: Initialize `h1` to store the sum of the first half of the digits
        int h2 = 0;  // Step 2: Initialize `h2` to store the sum of the second half of the digits
        int x = 0;  // Step 3: Initialize `x` to check for invalid digits

        // Step 4: Enter a for loop to iterate over each digit in the number
        for (int i = 0; i < n; i++) {
            char digit = number.charAt(i);  // Step 5: Get the current digit as a character
            if (digit!= '4' && digit!= '7') {  // Step 5: Check if the current digit is invalid
                System.out.println("NO");  // Step 5: Print "NO" and break the loop if an invalid digit is found
                x = 1;  // Step 5: Set `x` to 1
                break;  // Step 5: Break out of the loop
            }
            if (i < n / 2) {  // Step 6: Add the digit to `h1` if it's in the first half
                h1 += digit - '0';  // Step 6: Convert the character digit to an integer and add it to `h1`
            } else {  // Step 6: Add the digit to `h2` if it's in the second half
                h2 += digit - '0';  // Step 6: Convert the character digit to an integer and add it to `h2`
            }
        }

        // Step 7: After the loop, check if `x` is still 0 and compare the sums of the first and second halves
        if (x == 0) {  // Step 7: Check if no invalid digit was found
            if (h1 == h2) {  // Step 7: Check if the sums are equal
                System.out.println("YES");  // Step 7: Print "YES" if the sums are equal
            } else {  // Step 7: Print "NO" if the sums are not equal
                System.out.println("NO");
            }
        }
    }
}
