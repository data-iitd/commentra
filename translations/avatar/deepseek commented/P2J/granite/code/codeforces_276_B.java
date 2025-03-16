
import java.util.Scanner;

public class codeforces_276_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        boolean x = true;
        int[] dt = new int[26];

        // Iterate over each character in the input string and update the frequency count in the array
        for (int i = 0; i < s.length(); i++) {
            dt[s.charAt(i) - 'a']++;
        }

        int cnt = 0;  // Initialize a counter to keep track of characters with an odd frequency
        x = true;  // Reset the boolean variable to track the result

        // Iterate over the array to determine if there is more than one character with an odd frequency
        for (int i = 0; i < 26; i++) {
            if (dt[i] % 2!= 0 && cnt < 1) {
                cnt++;
            } else if (dt[i] % 2!= 0 && cnt >= 1) {
                x = false;
                break;
            }
        }

        // Determine the output based on the value of cnt and the length of the input string
        if (x) {
            System.out.println("First");  // Print "First" if there is at most one character with an odd frequency
        } else if (!x && s.length() % 2 == 0) {
            System.out.println("Second");  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
        } else if (!x && s.length() % 2!= 0) {
            System.out.println("First");  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
        }
    }
}
