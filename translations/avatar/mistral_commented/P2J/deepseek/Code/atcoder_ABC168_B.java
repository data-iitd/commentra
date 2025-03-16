import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the integer K from the standard input
        int K = scanner.nextInt();

        // Read a string S from the standard input
        String S = scanner.next();

        // Check if the length of the string S is less than or equal to K
        if (S.length() <= K) {

            // If the condition is true, print the string S
            System.out.println(S);
        } else {

            // If the condition is false, print a slice of the string S
            // from the beginning to the index K, followed by three dots '...'
            System.out.println(S.substring(0, K) + "...");
        }
    }
}

