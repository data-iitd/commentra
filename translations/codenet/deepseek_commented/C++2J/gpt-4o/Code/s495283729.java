import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int flag = 0;

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Check if the index is even
            if (i % 2 == 0) {
                switch (s.charAt(i)) {
                    // Check if the character is 'R', 'U', or 'D'
                    case 'R':
                    case 'U':
                    case 'D':
                        break;
                    default:
                        flag = 1;
                        break;
                }
            } else {
                // Check if the index is odd
                switch (s.charAt(i)) {
                    // Check if the character is 'L', 'U', or 'D'
                    case 'L':
                    case 'U':
                    case 'D':
                        break;
                    default:
                        flag = 1;
                        break;
                }
            }
        }

        if (flag == 0) {
            // If no invalid characters were found, print "Yes"
            System.out.println("Yes");
        } else {
            // If invalid characters were found, print "No"
            System.out.println("No");
        }

        scanner.close();
    }
}
// <END-OF-CODE>
