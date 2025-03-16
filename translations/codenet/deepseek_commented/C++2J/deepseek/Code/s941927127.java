import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String W = scanner.next();
        
        // Convert the string to a character array
        char[] charArray = W.toCharArray();
        
        // Sort the character array
        Arrays.sort(charArray);
        
        // Check for character pairs
        for (int i = 0; i < charArray.length; i += 2) {
            if (i + 1 >= charArray.length || charArray[i] != charArray[i + 1]) {
                // If a character is not followed by its pair, output "No" and exit
                System.out.println("No");
                return;
            }
        }
        
        // Output result
        // If all characters are in pairs, the program outputs "Yes"; otherwise,
        // it outputs "No".
        System.out.println("Yes");
    }
}
