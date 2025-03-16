import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();

        // Initialize a variable i with value 2
        int i = 2;

        // Start a for loop that runs as long as i is less than or equal to the length of the string S
        while (i <= S.length()) {

            // Check if the first half of the string S (from index 0 to (len(S)-i)/2) is equal to the second half of the string S (from index (len(S)-i)/2 to len(S)-i)
            if (S.substring(0, (S.length() - i) / 2).equals(S.substring((S.length() - i) / 2, S.length() - i))) {

                // If the condition is true, print the length of the substring (len(S) - i) and break out of the loop
                System.out.println(S.length() - i);
                break;
            }

            // Increment the value of i by 2
            i += 2;
        }
    }
}
