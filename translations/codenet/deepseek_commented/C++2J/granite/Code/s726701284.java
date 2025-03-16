
import java.util.Scanner;

public class s726701284{
    public static void main(String[] args) {
        // Step 1: Read a string from the user
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        // Step 2: Iterate through each letter from 'a' to 'z'
        for (char i = 'a'; i <= 'z'; i++) {
            // Step 3: Count how many times the current letter appears in the input string
            int a = 0;
            for (int j = 0; j < s.length(); j++) {
                if (i == s.charAt(j)) {
                    a++;
                }
            }

            // Step 4: If the letter does not appear in the input string, print it and break out of the loop
            if (a == 0) {
                System.out.println(i);
                break;
            }

            // Step 5: If all letters from 'a' to 'z' appear in the input string, print "None"
            if (i == 'z') {
                System.out.println("None");
                break;
            }
        }
    }
}
