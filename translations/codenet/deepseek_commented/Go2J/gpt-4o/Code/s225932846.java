import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Read a string S from the standard input
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        // Iterate over the string in steps of 2, starting from index 2 up to the length of the string
        for (int i = 2; i <= S.length(); i += 2) {
            // Check if the substring from the start to the middle of the remaining part of the string
            // is equal to the substring from the middle of the remaining part of the string to the end
            String firstHalf = S.substring(0, (S.length() - i) / 2);
            String secondHalf = S.substring((S.length() - i) / 2, S.length() - i);
            if (firstHalf.equals(secondHalf)) {
                // If a match is found, print the length of the string minus the current step size and break out of the loop
                System.out.println(S.length() - i);
                break;
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
