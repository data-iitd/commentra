import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable S to hold the input string
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        
        // Iterate over even lengths of the string from 2 to the length of S
        for (int i = 2; i <= S.length(); i += 2) {
            // Check if the first half of the string (up to the current length minus i)
            // is equal to the second half of the string (from the middle to the current length minus i)
            if (S.substring(0, (S.length() - i) / 2).equals(S.substring((S.length() - i) / 2, S.length() - i))) {
                // If they are equal, print the length of the string minus i
                // This gives the length of the string that is not part of the repeated pattern
                System.out.println(S.length() - i);
                // Exit the loop after finding the first match
                break;
            }
        }
        scanner.close();
    }
}
// <END-OF-CODE>
