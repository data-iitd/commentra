import java.util.Scanner;

public class Main {
    // Defining constants
    static final long inf = (long) 1e20;
    static final double eps = 1.0 / 1e10;
    static final int mod = 1000000007;

    // Function to read a single integer from standard input
    static int readInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Function to read a single string from standard input
    static String readString(Scanner scanner) {
        return scanner.next();
    }

    // Main function
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading input string and number of occurrences of '1' required
        String s = readString(scanner);
        int k = readInt(scanner);

        // Finding the length of the substring consisting only of '1's
        int l = 0;
        for (char c : s.toCharArray()) {
            if (c != '1') {
                // If the length of the substring is greater than or equal to the required number of occurrences, return 1
                if (l >= k) {
                    System.out.println(1);
                    return;
                }
                break;
            }
            l++;
        }

        // If the length of the substring is less than the required number of occurrences, return the character after the substring
        System.out.println(s.charAt(l));
    }
}
// <END-OF-CODE>
